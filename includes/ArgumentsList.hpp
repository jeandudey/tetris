#pragma once

#include <cstdio>
#include <vector>
#include <string>

class ArgumentsList {
 public:
  ArgumentsList(int argc, const char **argv)
    : arguments_(argc)
  {
    for (int i = 0; i < argc; i++)
        arguments_[i] = std::string(argv[i]);
  }

  std::string operator[](std::size_t index) { return arguments_[index]; }

 private:
  std::vector<std::string> arguments_;
};
