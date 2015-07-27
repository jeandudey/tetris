#include "SDLWrapper.hpp"

SDL::SDL(Uint32 flags)
{
    if (SDL_Init(flags) != 0)
        BOOST_THROW_EXCEPTION(sdl_error() << sdl_geterror(SDL_GetError()));
}

SDL::~SDL()
{
    SDL_Quit();
}
