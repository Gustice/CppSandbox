add_library(MainFrameComponent MyProcess.cpp)
target_include_directories(MainFrameComponent PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(MainFrame main.cpp)
target_link_libraries(MainFrame PUBLIC MainFrameComponent)
