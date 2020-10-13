#include "../../GameClient/Public/GnomeBoiGameClient.h"
#include "../../GameClient/Public/GameListDefinition.h"
#include "../../Firmware/Public/GnomeBoiFirmwareAPI.h"
#include <Arduino.h>

namespace {

    // game  context
    GnomeBOI::GameClient::Game* currentGame = NULL;

    // game list
    short gameCount;

    // game selector navigation
    short selector = 0;
    short currentPage = 0;
    short pageCount;
    short gamesCountThisPage = 0;

    // animation
    uint8_t navigationDelayFrames = 0;
    bool requiresCleanRedraw = true;


    /**
     *  internal Draws UserMenu...
     */
    void _redrawUserMenu()
    {
        // clear game names 
        GnomeBOI::Display::fillRect(1, 12, 128, 40, 0x0000);

        // display games //
        for (uint8_t i = 0; i < gamesCountThisPage; i++) {

            uint16_t color = 0xFFFF;

            if (selector == i % 4)
                color = 0x07FF; // cyan

            GnomeBOI::Display::drawText(1, 12 + 10 * i, 1, color, false, GnomeBOI::GameClient::MY_GAMES_LIST[i + 4 * currentPage].gameName);
        }

        // display bottom bar //
        String s = "PAGE ";
        s += (currentPage + 1);
        s += "/";
        s += pageCount;

        GnomeBOI::Display::fillRect(1, 56, 128, 8, 0x0000); // clean
        GnomeBOI::Display::drawText(48, 56, 1, 0xFFFF, false, s.c_str());
    }

    GnomeBOI::GameClient::GameConstructorProxy _drawUserMenu() {
        if (requiresCleanRedraw)
        {
            gameCount = sizeof(GnomeBOI::GameClient::MY_GAMES_LIST) / sizeof(GnomeBOI::GameClient::MY_GAMES_LIST[0]);
            pageCount = (gameCount + 4 - 1) / 4; // integer division with ceiling approximation
            gamesCountThisPage = min(4, gameCount - (4 * currentPage)); //...

            // draw the static part of the menu just once
            GnomeBOI::Display::clean(0x0000);
            GnomeBOI::Display::fillRect(0, 0, 128, 9, 0xFFFF);
            GnomeBOI::Display::drawText(1, 1, 1, 0x0000, false, "GnomeBOI  v0.3");
            GnomeBOI::Display::fillRect(0, 54, 128, 1, 0xFFFF); // BOTTOM LINE

            _redrawUserMenu();

            requiresCleanRedraw = false;
            return NULL; // the first time we draw the menu, ignore inputs and return.
        }


        // if game is selected, return the selected GameConstructorProxyPtr
        if (isButtonPressed(GnomeBOI::Input::BUTTON_A)) {
            requiresCleanRedraw = true;
            return  GnomeBOI::GameClient::MY_GAMES_LIST[selector + 4 * currentPage].gameConstructorProxy;
        }

        // if all buttons are released, it means the next input
        // doesn't need to wait (user is clicking and releasing to scroll)
        //
        // instead, if the user holds the button, wait a delay between
        // suqsequent inputs to avoid scrolling too fast.
        //
        if (!isButtonPressed(GnomeBOI::Input::ARROW_UP) && !isButtonPressed(GnomeBOI::Input::ARROW_DOWN) && !isButtonPressed(GnomeBOI::Input::ARROW_LEFT) && !isButtonPressed(GnomeBOI::Input::ARROW_RIGHT)) {

            navigationDelayFrames = 0;
            return NULL; // nothing to update

        }
        else if (navigationDelayFrames > 0) {

            navigationDelayFrames--;
            return NULL;
        }

        // when you reach here, navigationDelayFrames is zero,
        // and the next input can be processed

        // scroll between pages...
        //
        if (isButtonPressed(GnomeBOI::Input::ARROW_LEFT) && !isButtonPressed(GnomeBOI::Input::ARROW_RIGHT))
        {
            selector = 0;
            currentPage--;
        }
        else if (!isButtonPressed(GnomeBOI::Input::ARROW_LEFT) && isButtonPressed(GnomeBOI::Input::ARROW_RIGHT))
        {
            selector = 0;
            currentPage++;
        }

        // else, scroll between games...
        //
        else if (isButtonPressed(GnomeBOI::Input::ARROW_UP) && !isButtonPressed(GnomeBOI::Input::ARROW_DOWN))
            selector--;

        else if (!isButtonPressed(GnomeBOI::Input::ARROW_UP) && isButtonPressed(GnomeBOI::Input::ARROW_DOWN))
            selector++;

        // otherwise, nothing to do...
        //
        else
            return NULL;

        // if the selector overflows the last element of the page,
        // or underflows the fist element of the page,
        // scroll to the next or previous page respectively.
        //
        if (selector < 0) {
            currentPage -= 1;
            selector = 3;
        }
        else if (selector > gamesCountThisPage - 1) { // gamesCountThisPage contains the number of games in this page
                                                  // it is always 4, except for last page when it can be 1,2,3 or 4.
            currentPage += 1;
            selector = 0;
        }

        // in the same way, loop between first and last page
        //
        currentPage = (currentPage + pageCount) % pageCount; // why this doesn't work? am i stupid?

        // (after the page was updated) re-calculates the number of games in this page.
        // if the last page does not have enough elements, select the last element.
        //
        gamesCountThisPage = min(4, gameCount - (4 * currentPage));
        if (selector >= gamesCountThisPage) {
            selector = gamesCountThisPage - 1;
        }

        // --- BEGIN DRAWING -- //
        navigationDelayFrames = 8;
        _redrawUserMenu();
        return NULL;

    }
    
}

void GnomeBOI::Runtime::onClientApplicationUpdate() {

    if (currentGame) {
        if (currentGame->onUpdate() != GnomeBOI::GameClient::GameState::RUNNING) {
            delete currentGame;
            currentGame = NULL;
        }
    }

    else {
        GnomeBOI::GameClient::GameConstructorProxy selectedGame = _drawUserMenu();
        if (selectedGame) {
            currentGame = selectedGame(); //instatiate
        }
    }
}