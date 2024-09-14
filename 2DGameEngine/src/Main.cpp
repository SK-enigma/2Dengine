#include <iostream>
#include "Game/Game.h"
#include "Logger/Logger.h"




int main(int argc, char* argv[]) {

    Game game;

    game.Initialize();
    game.Run();
    game.Destroy();
   
    return 0;
}