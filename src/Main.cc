#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> ArgumentsList;

void fill_arguments(ArgumentsList &args, int argc, const char **argv)
{
    for (int i = 0; i < argc; i++)
        args[i] = std::string(argv[i]);
}

void print_arguments(const ArgumentsList &arguments)
{
    for (int i = 0; i < arguments.size(); i++)
        std::cout << "arguments[" << i << "]: " << arguments[i] << std::endl;
}

int main(int argc, const char **argv)
{
    ArgumentsList arguments(argc);

    fill_arguments(arguments, argc, argv);
    print_arguments(arguments);
    return 0;
}
