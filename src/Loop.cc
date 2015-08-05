#include "Loop.hpp"
#include "Timer.hpp"

Loop::Loop(SDLWindow &window)
    : window_(window),
      game_(window)
{
}

void Loop::run()
{
    // ms/fps
    const int ticks_per_frame = 1000 / 60;

    Timer fpstimer;
    Timer captimer;

    int countedframes(0);
    fpstimer.start();

    while (game_.running()) {
        captimer.start();

        game_.handle_events();

        float average_fps = countedframes / (fpstimer.get_ticks() / 1000.f);
        if (average_fps > 2000000 )
            average_fps = 0;

        game_.update();
        game_.draw();

        window_.swap();

        ++countedframes;

        int frameticks = captimer.get_ticks();
        if (frameticks < ticks_per_frame)
            SDL_Delay(ticks_per_frame - frameticks);
    }
}
