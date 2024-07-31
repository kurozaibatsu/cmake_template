find_package(GTest REQUIRED HINTS $ENV{GTEST_HOME})

add_executable(mylib_test)
target_sources(mylib_test PRIVATE "${CMAKE_CURRENT_LIST_DIR}/test.cpp")
target_link_libraries(mylib_test PRIVATE GTest::gtest_main mylib::mylib)

include(GoogleTest)
gtest_discover_tests(mylib_test)
