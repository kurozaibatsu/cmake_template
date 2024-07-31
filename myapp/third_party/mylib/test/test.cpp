#include "module_a/module_ab.hpp"
#include <cstdio>
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(mylib, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(mylib, do_something) {
  EXPECT_EQ(1, module_a::do_something(0));
  EXPECT_EQ(0, module_a::do_something(-1));
}