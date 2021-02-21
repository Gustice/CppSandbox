set(dynLibSrcs dynLib.cpp util.cpp)
add_library(dynamicLibrary SHARED ${dynLibSrcs})
target_include_directories(dynamicLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

message("Dll Output Folder is: " ${CMAKE_CURRENT_BINARY_DIR})
message("Dll Copy-Path: " ${PROJECT_BINARY_DIR})

set(LibName "libdynamicLibrary.dll")
add_custom_command(TARGET dynamicLibrary POST_BUILD      # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different        # which executes "cmake - E copy_if_different..."
        "${CMAKE_CURRENT_BINARY_DIR}/${LibName}"         # <--this is in-file
        "${PROJECT_BINARY_DIR}/${LibName}"               # <--this is out-file path
        )
## set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}) # does not work
