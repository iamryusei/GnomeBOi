#ifndef __GAME_PONG_H_
#define __GAME_PONG_H_

#include "../Firmware/Public/GnomeBoiFirmwareAPI.h"
#include "../GameClient/Public/GnomeBoiGameClient.h"

#include <stdint.h>
#include <math.h>

#include <Arduino.h>

//constexpr float PI = 3.14159265;

using GnomeBoiGame = GnomeBOI::GameClient::Game;
using namespace GnomeBOI::Input;

class GamePong : public GnomeBoiGame
{
	private:
		static constexpr uint8_t BALL_SIZE     = 3;
		static constexpr uint8_t PADDLE_WIDTH  = 3;
		static constexpr uint8_t PADDLE_HEIGHT = 8;
		static constexpr uint8_t PADDLE_OFFSET_Y_A = 5;
		static constexpr uint8_t PADDLE_OFFSET_Y_B = GnomeBOI::Display::DISPLAY_WIDTH_PX - PADDLE_OFFSET_Y_A;

		

		// position of Player A
		uint8_t positionA = GnomeBOI::Display::DISPLAY_HEIGHT_PX / 2;
		uint8_t oldPositionA;

		// position of Player B
		uint8_t positionB = GnomeBOI::Display::DISPLAY_HEIGHT_PX / 2; 
		uint8_t oldPositionB;

		// position of Ball
		float ballPositionX = GnomeBOI::Display::DISPLAY_WIDTH_PX  / 2;
		float ballPositionY = GnomeBOI::Display::DISPLAY_HEIGHT_PX / 2;
		uint8_t ballDirectionDegrees = 45;
		float ballDirectionRadians;
		float ballSpeed = 2;

		// game logic
		bool isHoldButtonA = true;
		uint8_t scoreA = 0;
		uint8_t scoreB = 0;
		uint8_t gameState = 0;

		static constexpr uint8_t GAMESTATE_MENU = 0;
		static constexpr uint8_t GAMESTATE_PLAY = 1;

	public:
		GamePong() {
			GnomeBOI::Display::clean(0x0AA0);
		}

		GnomeBOI::GameClient::GameState onUpdate()
		{
			if (gameState == GAMESTATE_MENU)
			{
				#pragma region DISPLAY GAME MENU
				{
					ballDirectionDegrees = (ballDirectionDegrees + 11) % 360; // random initial angle depends
																			  // on how much time you wait before
																			  // starting the game. This avoid importing
																			  // time libraries.

					GnomeBOI::Display::drawText(0, 0, 2, 0xDE66, false, "Tennis!"); //Game Title
					GnomeBOI::Display::drawText(0, 30, 1, 0xDE66, false, "Press \"A\"\n   to Start"); //Option

					if (!isHoldButtonA && isButtonPressed(BUTTON_A))
					{
						gameState = GAMESTATE_PLAY;
					}
					
					isHoldButtonA = isButtonPressed(BUTTON_A);
					return;
				}
				#pragma endregion
			}

			else if (gameState == GAMESTATE_PLAY)
			{
				#pragma region GAME PLAY
				{
					// INPUT
					if (GnomeBOI::Input::isButtonPressed(GnomeBOI::Input::ARROW_UP) && !GnomeBOI::Input::isButtonPressed(GnomeBOI::Input::ARROW_DOWN))
						positionA--;
					else if (GnomeBOI::Input::isButtonPressed(GnomeBOI::Input::ARROW_DOWN) && !GnomeBOI::Input::isButtonPressed(GnomeBOI::Input::ARROW_UP))
						positionA++;

					// CHECK COLLISION with SCREEN SIDES: BOUNCE
					if (ballPositionY < 1 || ballPositionY > GnomeBOI::Display::DISPLAY_HEIGHT_PX - 1) {
						ballDirectionDegrees = 360 - ballDirectionDegrees;
					}

					// CHECK SCORE
					if (ballPositionX <= 1 || ballPositionX >= GnomeBOI::Display::DISPLAY_WIDTH_PX - 1) {
						ballPositionX = GnomeBOI::Display::DISPLAY_WIDTH_PX / 2;
						ballPositionY = GnomeBOI::Display::DISPLAY_HEIGHT_PX / 2;
					}

					// CHECK COLLISION with PLAYER A
					else if (ballPositionX == PADDLE_OFFSET_Y_A && ballPositionX >= positionA && ballPositionX <= positionA + PADDLE_HEIGHT)
					{
						short impactX = (ballPositionX - (positionA + PADDLE_HEIGHT / 2));
						ballDirectionDegrees = 75 * (impactX / PADDLE_HEIGHT);
					}

					// UPDATE BALL POSITION
					ballPositionX += ballSpeed * cos(ballDirectionDegrees * PI / 180);
					ballPositionY -= ballSpeed * sin(ballDirectionDegrees * PI / 180);

					// DRAW BALL
					GnomeBOI::Display::clean(0x0AA0);
					GnomeBOI::Display::fillRect(floor(ballPositionX) - 1, floor(ballPositionY) - 1, 3, 3, 0xFFFF);

					// DRAW
					//if (OldPositionA != positionA) {

						// draw OLDER

						//GnomeBOI::Display::drawRect(5, OldPositionA - 6, 3, 12, 0x0AA0);
						//GnomeBOI::Display::drawRect(96 - 5, 64 - 6, 3, 12, 0x0AA0);

						// draw new
					GnomeBOI::Display::drawRect(5, positionA - 6, 3, 12, 0xFFFF);
					GnomeBOI::Display::drawRect(96 - 5, 64 - 6, 3, 12, 0xFFFF);



					oldPositionA = positionA;
					//}

					GnomeBOI::Display::drawText(2, 2, 2, 0xF700, false, "0   -   1");

					return GnomeBOI::GameClient::GameState::RUNNING;
				}
				#pragma endregion
			}



			
		}

		~GamePong() {}
};

GnomeBOI::GameClient::Game* createGamePong() {
	return new GamePong();
}

#endif