#include <iostream>

#include "ArgumentsList.hpp"
#include "SDLWrapper.hpp"
#include "Tetris.hpp"
#include "Loop.hpp"

int main(int argc, char *argv[])
{
    ArgumentsList arguments(argc, argv);

    try {
        SDL sdl(SDL_INIT_EVERYTHING);
        SDLWindow window("Tetris",
                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                        640, 480);

        Tetris game(window);
        Loop loop(&game);

        loop.run();

        window.close();
    } catch (boost::exception &e) {
        std::cerr << "-- Diagnostic information:" << std::endl;
        std::cerr << boost::diagnostic_information(e) << std::endl;
    }
    return 0;
}
