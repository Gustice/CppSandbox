cmake_minimum_required (VERSION 3.5)

# Defines Project 
project(DynamicLibraryUsage)

# include subdirectory ... must contain a CMakeLists.txt-File
add_subdirectory(statLib)
add_subdirectory(dynLib)
list(APPEND EXTRA_LIBS )

# Adds new Executable => Yields a Exe with given name
add_executable(LibUsage main.cpp)

# Sets Compiler Include Path for target # Note this is better approach then the genric commands like "include_directories"
target_link_libraries(LibUsage staticLibrary dynamicLibrary)

# Sets Compiler Include Path
include_directories(${CMAKE_SOURCE_DIR}/statLib )
