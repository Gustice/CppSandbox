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


## This must somehow be placed in this root file
enable_testing()
# does the application run
add_test(NAME Runs COMMAND DemoApp 0)

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# do a bunch of result based tests
do_test(DemoApp 4 "4 is 4")
do_test(DemoApp 9 "9 is 9")
