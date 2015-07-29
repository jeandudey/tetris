#include <iostream>

#include "ArgumentsList.hpp"
#include "SDLWrapper.hpp"
#include "Piece.hpp"

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

        renderer.set_draw_color(0, 255, 0, 255);
        Piece piece(Piece::Type::Square);

        piece.draw(renderer, 1);

        renderer.destroy();
        window.close();
    } catch (boost::exception &e) {
        std::cerr << "-- Diagnostic information:" << std::endl;
        std::cerr << boost::diagnostic_information(e) << std::endl;
    }
    return 0;
}
