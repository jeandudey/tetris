#include "Loop.hpp"

Loop::Loop(Tetris *game)
    : game_(nullptr)
{
    if (game == nullptr)
        BOOST_THROW_EXCEPTION(loop_error() << loop_error_string("game can't be nullptr"));
    else
        game_ = game;
}

void Loop::run()
{
    while (game_->running()) {
        game_->handle_events();
        game_->update();
        game_->draw();
    }
}
