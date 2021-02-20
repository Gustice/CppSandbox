cmake_minimum_required(VERSION 3.6)

project(gTestDemo)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest) # git clone https://github.com/google/googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(source)
add_subdirectory(library)

enable_testing()
add_subdirectory(test)
