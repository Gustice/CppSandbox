cmake_minimum_required (VERSION 3.5)

# set the project name and version
project(CMakeEval VERSION 1.0)
# Debug-Message
message("####################################################")
message("### Project: " ${PROJECT_NAME} " " ${PROJECT_VERSION})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_STATLIB "Use static Library" ON)

#   add_subdirectory(statLib) ## Better to include conditionally
if(USE_STATLIB)
  add_subdirectory(statLib)
  list(APPEND EXTRA_LIBS staticLibrary)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/statLib")
endif()

# include subdirectories -> must contain CMakeLists
add_subdirectory(dynLib)
add_subdirectory(app)
