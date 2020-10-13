/**
 *
 *
 */
#if 0
#include "../framework/public/GnomeBoi.h"

using namespace GnomeBoi::Runtime;

public class GameSnake : Game
{
	private:
		unsigned short snake[256];	// describes the snake position.
									// snake[0] is the head,
									// snake[lenght - 1] is the tail
									//
									// unsigned short value is the coordinate of a 16x16 grid:
									// MSB: 4 bit for positionY | LSB: 4 bit for positionX

		unsigned short lenght;
		char direction;
		unsigned short applePosition;
		
		inline spawnApple() { }

		inline _updateSnakePosition() {

			switch (direction) {
				case "U":
					break;
				case "D":
					break;
				case "L":
					break;
				case "R":
					break;
			}
		}

	public:
		GameSnake() {	}

		GameState onUpdate()
		{
			// read input
			// ...

			// move
			// ...

			// check apple collision
			// ...

			// check self collision
			// ...



		
			return GameState::RUNNING;
		}
};
#endif
