#include "Timer.hpp"

Timer::Timer()
    : start_ticks_(0),
      paused_ticks_(0),
      started_(false),
      paused_(false)
{
}

void Timer::start()
{
    started_ = true;
    paused_ = false;

    start_ticks_ = SDL::get_ticks();
    paused_ticks_ = 0;
}

void Timer::stop()
{
    started_ = false;
    paused_ = false;

    start_ticks_ = 0;
    paused_ticks_ = 0;

}
void Timer::pause()
{
    if (started_ && !paused_) {
        paused_ = true;

        paused_ticks_ = SDL::get_ticks() - start_ticks_;
        start_ticks_ = 0;
    }
}

void Timer::unpause()
{
    if (started_ && paused_) {
        paused_ = false;
        start_ticks_ = SDL::get_ticks() - paused_ticks_;

        paused_ticks_ = 0;
    }
}

Uint32 Timer::get_ticks()
{
    if (started_) {
        if (paused_)
            return paused_ticks_;
        else
            return SDL::get_ticks() - start_ticks_;
    }

    return 0;
}
