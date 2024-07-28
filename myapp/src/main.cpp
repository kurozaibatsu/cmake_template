#include "module_a/module_ab.hpp"
#include <cstdio>
#if __has_include("timestamp.h")
#include "timestamp.h"
#endif

int main() {
  std::puts("Version: " VERSION_MAJOR "." VERSION_MINOR "." TIMESTAMP);
  module_a::do_something();
}