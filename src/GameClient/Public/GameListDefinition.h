#ifndef __AAAAAAAAAAAAAAAA
#define __AAAAAAAAAAAAAAAA

#include "../../GameClient/Public/GnomeBoiGameClient.h"

// include games headers here...
#include "../../Games/GamePong.h"

namespace GnomeBOI {
    namespace GameClient {

        constexpr GameEntry  MY_GAMES_LIST[] = {
            {"Pong", &createGamePong},
            {"Snake", nullptr},
            {"Tetris", nullptr},
            {"Arkanoid", nullptr},
            {"Mr.Hammer", nullptr},
            {"Danmaku", nullptr},
            {"F1", nullptr},
        };
    }
}

#endif