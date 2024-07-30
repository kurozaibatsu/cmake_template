#include "module_a/module_ab.hpp"
#include <cstdio>
#include <string>

int main(int argc, char **argv) {
  printf("argc: %d\n", argc);
  if (2 > argc) {
    return 0;
  }
  auto result = module_a::do_something(std::stoi(argv[1]));
  printf("%d\n", result);
}