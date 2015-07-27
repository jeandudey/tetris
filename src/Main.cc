#include <iostream>

#include "ArgumentsList.hpp"

int main(int argc, const char **argv)
{
    ArgumentsList arguments(argc, argv);

    std::cout << arguments[0] << std::endl;
    return 0;
}
