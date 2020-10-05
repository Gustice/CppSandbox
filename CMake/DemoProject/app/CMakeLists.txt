include_directories(${CMAKE_SOURCE_DIR}/lib)

set(appSrcs main.cpp process.cpp)
add_executable(DemoApp ${appSrcs})

target_link_libraries(DemoApp utilLib)

install(TARGETS DemoApp DESTINATION bin)
