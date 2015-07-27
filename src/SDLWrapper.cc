#include "SDLWrapper.hpp"

SDL::SDL(Uint32 flags)
{
    SDL_Init(flags);
}

SDL::~SDL()
{
    SDL_Quit();
}
