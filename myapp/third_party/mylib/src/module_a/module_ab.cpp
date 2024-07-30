#include "module_ab.hpp"
#include <cstdio>

namespace module_a {

extern int do_something(int i) {
  std::printf("%s\n", __PRETTY_FUNCTION__);
  return i + 1;
}

} // namespace module_a