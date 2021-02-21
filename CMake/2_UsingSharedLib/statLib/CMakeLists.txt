set(statLibSrcs statLib.cpp)
add_library(staticLibrary STATIC ${statLibSrcs})
target_link_directories(staticLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
