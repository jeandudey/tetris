#include <iostream>

#include "ArgumentsList.hpp"
#include "SDLWrapper.hpp"
#include "Pieces.hpp"

int main(int argc, char *argv[])
{
    ArgumentsList arguments(argc, argv);

    try {
        SDL sdl;
        SDLWindow window("Tetris",
                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                        640, 480);

        SDLRenderer renderer(window);

        renderer.set_draw_color(255, 0, 0, 255);
        renderer.clear();

        renderer.destroy();
        window.close();
    } catch (boost::exception &e) {
        std::cerr << "-- Diagnostic information:" << std::endl;
        std::cerr << boost::diagnostic_information(e) << std::endl;
    }
    return 0;
}
