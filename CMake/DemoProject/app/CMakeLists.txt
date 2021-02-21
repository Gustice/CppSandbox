configure_file(Version.h.in Version.h)
configure_file(Config.h.in Config.h)
message("### Project: " ${PROJECT_NAME} " " ${PROJECT_VERSION})

# Sets Compiler Include Path
include_directories(${CMAKE_SOURCE_DIR}/dynLib )
include_directories(${CMAKE_SOURCE_DIR}/statLib )

set(appSrcs main.cpp process.cpp)

# Adds new Executable => Yields a Exe with giben Name
add_executable(DemoApp ${appSrcs})
# Sets Compiler Include Path for target # Note this is better approach then the genric commands like "include_directories"
target_include_directories(DemoApp PUBLIC "${PROJECT_BINARY_DIR}/app" ${EXTRA_LIBS})

target_link_libraries(DemoApp dynamicLibrary ${EXTRA_LIBS})

install(TARGETS DemoApp DESTINATION bin)




