#include "SDLWrapper.hpp"

// SDL

SDL::SDL(Uint32 flags)
    : initialized_(false)
{
    if (SDL_Init(flags) != 0)
        BOOST_THROW_EXCEPTION(sdl_error() << sdl_geterror(SDL_GetError()));

    initialized_ = true;
}

SDL::~SDL() { SDL_Quit(); }

// Window

SDLWindow::SDLWindow(const std::string &title, int x, int y, int w, int h, Uint32 flags)
    : window_(SDL_CreateWindow(title.c_str(), x, y, w, h, flags)),
      created_(false)

{
    if (window_ == NULL)
        BOOST_THROW_EXCEPTION(sdl_error() << sdl_geterror(SDL_GetError()));
    else
        created_ = true;
}

SDL_Window *SDLWindow::get() { return window_; }

void SDLWindow::swap()
{
    SDL_GL_SwapWindow(window_);
}

void SDLWindow::close()
{
    SDL_DestroyWindow(window_);
}

// Renderer

SDLRenderer::SDLRenderer(SDLWindow &window, Uint32 flags)
    : renderer_(SDL_CreateRenderer(window.get(), -1, flags)),
      created_(false)

{
    if (renderer_ == NULL)
        BOOST_THROW_EXCEPTION(sdl_error() << sdl_geterror(SDL_GetError()));
    else
        created_ = true;
}

SDL_Renderer *SDLRenderer::get() { return renderer_; }

void SDLRenderer::set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (SDL_SetRenderDrawColor(renderer_, r, g, b, a) != 0)
        BOOST_THROW_EXCEPTION(sdl_error() << sdl_geterror(SDL_GetError()));
}

void SDLRenderer::draw_rectangle(const SDL_Rect *rect)
{
    if (SDL_RenderDrawRect(renderer_, rect) != 0)
        BOOST_THROW_EXCEPTION(sdl_error() << sdl_geterror(SDL_GetError()));
}

void SDLRenderer::clear()
{
    if (SDL_RenderClear(renderer_) != 0)
        BOOST_THROW_EXCEPTION(sdl_error() << sdl_geterror(SDL_GetError()));
}

void SDLRenderer::destroy()
{
    SDL_DestroyRenderer(renderer_);
}

SDLGL::SDLGL(SDLWindow &window)
    : context_(SDL_GL_CreateContext(window.get())),
      created_(false)

{
    if (context_ == NULL)
        BOOST_THROW_EXCEPTION(sdl_error() << sdl_geterror(SDL_GetError()));
    else
        created_ = true;
}

SDL_GLContext SDLGL::get() { return context_; }

void SDLGL::set_attribute(SDL_GLattr attr, int value)
{
    if (SDL_GL_SetAttribute(attr, value) != 0)
        BOOST_THROW_EXCEPTION(sdl_error() << sdl_geterror(SDL_GetError()));
}

bool SDLGL::swap_interval(int interval)
{
    return SDL_GL_SetSwapInterval(interval) != 0;
}
