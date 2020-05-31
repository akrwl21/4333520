# CMakeLists.txt (fragment of)
cmake_minimum_required(VERSION 2.8.0)
 project(test1)

include(CTest)

add_library( maths static test1.cpp )
# ...
# description of executables and libraries # ...
add_executable(test1 maths.cpp) 

target_link_libraries(test1 maths)

add_test(test1 test1)