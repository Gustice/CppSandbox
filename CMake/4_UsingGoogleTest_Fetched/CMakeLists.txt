cmake_minimum_required(VERSION 3.11)
include(FetchContent)

project(gTestDemo)
set(CMAKE_CXX_STANDARD 14)

# add_subdirectory(googletest) # git clone https://github.com/google/googletest
FetchContent_Declare(googletest
                     GIT_REPOSITORY https://github.com/google/googletest
                     GIT_TAG master
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(source)
add_subdirectory(library)

enable_testing()
add_subdirectory(test)
