#include <SDL.h>

#include <iostream>

#include "engine/Game.h"
#include "engine/Timer.h"
#include "engine/Window.h"

#include "engine/Cube.h"

using std::cout;
using std::endl;

LogConfig LOG_CONFIG = {};

int main(int argc = 0, char **argv = nullptr) {
    if (argc > 0) {
        for (int i = 0; i < argc; ++i) {
            cout << argv[i] << endl;
        }
    }

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 640;

    // Init logging
    LOG_CONFIG.reporting_level = Debug;
    LOG_CONFIG.restart = true;
    if (LOG_CONFIG.restart) {
        Log::restart();
    }

    // Init window
    Window window = Window("Pacman");
    if (!window.init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false)) {
        return 1;
    }

    // Init game
    Timer timer;
    Game game;
    game.init(SCREEN_WIDTH, SCREEN_HEIGHT);

    game.load();

    for (int i = 0; i < 1; i++)
    {
        Cube c;
        c.Load(SCREEN_WIDTH, SCREEN_HEIGHT, game.shader);
        game.cubesToMove.push_back(c);
    }
    
    //game.load();

	// Delta time in seconds
	float dt;

    // Game loop
    while (game.isRunning) {
        dt = static_cast<float>(timer.computeDeltaTime()) / 1000.0f;
        window.updateFpsCounter(dt);

        game.handleInputs();

        window.clearBuffer();

        for (Cube &cube : game.cubesToMove) 
        {
            cube.Update(dt);

            cube.Render(game.shader);
        }

        window.swapBuffer();


        // Delay frame if game runs too fast
        timer.delayTime();
    }

    // Exit game
    for (auto &cube : game.cubesToMove) 
    {
        cube.Clean();
    }
    
    window.clean();
    return 0;
}