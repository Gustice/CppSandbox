cmake_minimum_required(VERSION 3.11)
project(catchDemo)

cmake_minimum_required(VERSION 3.11)
Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1
)
FetchContent_MakeAvailable(Catch2)
# list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
# Note: Include now is "catch2/catch.hpp"

add_subdirectory(source)

enable_testing()
add_subdirectory(tests)
