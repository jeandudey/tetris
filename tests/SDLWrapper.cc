#include <gtest/gtest.h>
#include <SDLWrapper.hpp>

TEST(SDLClass, Constructor)
{
    SDL sdl(SDL_INIT_EVERYTHING);

    ASSERT_EQ(sdl.initialized(), true);
}

TEST(SDLWindowClass, Constructor)
{
    SDLWindow window("test", 0, 0, 1, 1);

    ASSERT_EQ(window.created(), true);

    window.close();
}

TEST(SDLRendererClass, Constructor)
{
    SDLWindow window("test", 0, 0, 1, 1);
    SDLRenderer renderer(window);

    ASSERT_EQ(renderer.created(), true);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
