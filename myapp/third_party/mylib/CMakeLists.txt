cmake_minimum_required(VERSION 3.25)
project(MyLib)

set(src_dir "src")
set(srcs "${src_dir}/module_a/module_ab.cpp")
# Calls to add_library() without any explicit library type check the current
# BUILD_SHARED_LIBS variable value. If it is true, then the default library type
# is SHARED. Otherwise, the default is STATIC.
add_library(mylib)
add_library(mylib::mylib ALIAS mylib)
target_sources(mylib PRIVATE ${srcs})
target_include_directories(mylib
                           PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/${src_dir}")

if(BUILD_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()
