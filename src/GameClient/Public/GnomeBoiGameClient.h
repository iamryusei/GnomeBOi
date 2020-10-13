/**
 * [SUMMARY]
 *  This header declares the public functions and data structures of GnomeBOI's game client:
 *  an interactive application that allows the user to launch multiple games.
 *  Each Game of GnomeBoi should extend the GameClient::Game class in order for it to be
 *  acknowledged by the GameClient as a runnable game, and hence be presented to the user
 *  in the game selection menu
 */

#ifndef __GNOMEBOI_GAME_CLIENT_H_
#define __GNOMEBOI_GAME_CLIENT_H_

#include <stdint.h>

namespace GnomeBOI {
    namespace GameClient {

        
        /**
         *  Enumeration that represents the current state of a game instance.
         */
        typedef enum GameState : uint8_t
        {
            RUNNING = 0,
            CLOSING = 1,
            ERROR   = 2,
        };


        /**
         *  TO-DO: Documentation
         */
        class Game {
            public:
                virtual GameState onUpdate() = 0;
        };


        /**
         *  TO-DO: Documentation
         */
        typedef Game* (*GameConstructorProxy)();


        /**
         *  TO-DO: Documentation
         */
        typedef struct GameEntry {
            char* gameName;
            GameConstructorProxy gameConstructorProxy;
        };
    }
}
#endif