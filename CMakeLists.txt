cmake_minimum_required(VERSION 3.5)
project(
  myapp
  VERSION 1.02
  LANGUAGES CXX)

set(BUILD_SHARED_LIBS OFF)
set(use_timestamp ON)

add_subdirectory("myapp/third_party/mylib")
add_subdirectory("myapp")

target_compile_features(mylib PRIVATE cxx_std_23)
target_compile_options(mylib PRIVATE -Wall -Wextra -Wpedantic -Werror)
set_target_properties(mylib PROPERTIES CXX_EXTENSIONS OFF)

target_compile_features(myapp PRIVATE cxx_std_23)
target_compile_options(myapp PRIVATE -Wall -Wextra -Wpedantic -Werror)
set_target_properties(myapp PROPERTIES CXX_EXTENSIONS OFF)
