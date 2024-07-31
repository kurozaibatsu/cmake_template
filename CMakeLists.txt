cmake_minimum_required(VERSION 3.25)
project(
  myapp
  VERSION 1.02
  LANGUAGES CXX)

option(BUILD_SHARED_LIBS "build shared libraries instead of static" OFF)
option(use_timestamp "define TIMESTAMP macro with time of build" ON)
option(BUILD_TESTING "build with ctest and Gtest" OFF)

add_subdirectory("myapp/third_party/mylib")
add_subdirectory("myapp")

target_compile_features(mylib PRIVATE cxx_std_23)
target_compile_options(mylib PRIVATE -Wall -Wextra -Wpedantic -Werror)
set_target_properties(mylib PROPERTIES CXX_EXTENSIONS OFF)

target_compile_features(myapp PRIVATE cxx_std_23)
target_compile_options(myapp PRIVATE -Wall -Wextra -Wpedantic -Werror)
set_target_properties(myapp PROPERTIES CXX_EXTENSIONS OFF)

if(BUILD_TESTING)
  enable_testing()
  add_test(NAME runs COMMAND myapp)
  set_property(TEST runs PROPERTY PASS_REGULAR_EXPRESSION "Version")
endif()
