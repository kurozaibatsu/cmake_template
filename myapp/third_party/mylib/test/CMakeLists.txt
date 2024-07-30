cmake_minimum_required(VERSION 3.5)
project(mylib_test)

add_executable(tests)
target_sources(tests PRIVATE "${CMAKE_CURRENT_LIST_DIR}/test.cpp")
target_link_libraries(tests PRIVATE mylib::mylib)

set(lib_name mylib)
add_test(NAME ${lib_name}_runs COMMAND tests)

function(do_something result)
  set(test_name "${lib_name}_do_something")
  foreach(arg IN LISTS ARGN)
    set(test_name "${test_name}_${arg}")
  endforeach()
  add_test(NAME ${test_name} COMMAND tests ${ARGN})
  set_tests_properties(${test_name} PROPERTIES PASS_REGULAR_EXPRESSION
                                               ${result})
endfunction()

do_something("2" 1 50)
