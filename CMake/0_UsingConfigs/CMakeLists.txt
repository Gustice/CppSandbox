cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(ConfigHeader VERSION 1.0)
# Set some cMake-Variables in order to place them into Config.h.in
set(MyString "DemoProject")
set(MyNumber 123)

## Options are displayed in the cMake GUI
option(USE_FLAG "Use some arbitrary flag to demonstrate configuration" ON)
# Option can be set in GUI or by command-Line cmake ../proj -DUSE_FLAG=ON
set(USE_FLAG ON) # Option is directly set for demo purpose 


if(USE_FLAG) # Confitional cMake statements
    message("## USE_FLAG is defiened")
endif()

if(NOT_USE_FLAG) # Confitional cMake statements
    message("## NOT_USE_FLAG is defiened")
endif()

# add the executable -> Later "ConfigHeader.exe"
add_executable(ConfigHeader UseConfigHeader.cpp)
# defines config-source file and output name (output will be written in binary-Tree)
configure_file(Config.h.in Config.h) # @..@ Variables will be replaced

# include directory of binary-dir in order to make configfile-output visible
target_include_directories(ConfigHeader PUBLIC 
                ${PROJECT_BINARY_DIR} # Add Root (Config File is placed here)
                )