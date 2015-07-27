#include <iostream>

#include "ArgumentsList.hpp"
#include "SDLWrapper.hpp"

int main(int argc, char *argv[])
{
    ArgumentsList arguments(argc, argv);

    try {
        SDL sdl;
    } catch (boost::exception &e) {
        std::cerr << boost::diagnostic_information(e) << std::endl;
    }
    return 0;
}
