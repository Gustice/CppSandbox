cmake_minimum_required (VERSION 3.5)

# Defines Project 
project(StaticLibraryUsage) 

# include subdirectory ... must contain a CMakeLists.txt-File
add_subdirectory(statLib)
list(APPEND EXTRA_LIBS )

# Adds new Executable => Yields a Exe with given name
add_executable(LibUsage main.cpp)
# Sets Compiler Include Path for target # Note this is better approach then the genric commands like "include_directories"
target_include_directories(LibUsage PUBLIC staticLibrary)
target_link_libraries(LibUsage staticLibrary)

# Sets Compiler Include Path
include_directories(${CMAKE_SOURCE_DIR}/statLib)
