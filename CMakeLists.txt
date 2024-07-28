cmake_minimum_required(VERSION 3.5)
project(myapp LANGUAGES CXX)

set(BUILD_SHARED_LIBS off)

add_subdirectory("myapp/third_party/mylib")
add_subdirectory("myapp")

target_compile_features(mylib PUBLIC cxx_std_23)
target_compile_options(mylib PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_compile_features(myapp PUBLIC cxx_std_23)
target_compile_options(myapp PRIVATE -Wall -Wextra -Wpedantic -Werror)