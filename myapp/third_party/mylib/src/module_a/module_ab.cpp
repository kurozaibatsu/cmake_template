#include "module_ab.hpp"
#include <cstdio>

namespace module_a {

extern void do_something(void) { std::printf("%s\n", __PRETTY_FUNCTION__); }

} // namespace module_a