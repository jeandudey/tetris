#include "Loop.hpp"

Loop::Loop(SDLWindow &window)
    : window_(window),
      game_(window)
{
}

void Loop::run()
{
    while (game_.running()) {
        game_.handle_events();
        game_.update();
        game_.draw();

        window_.swap();
    }
}
