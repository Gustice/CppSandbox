add_library(Catch INTERFACE)
target_include_directories(Catch
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

enable_testing()

add_executable(MainTests
    mainTest.cpp
    MyProcessTests.cpp
)
target_include_directories(MainTests
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(MainTests
	Catch
	MainFrameComponent
)

add_test(NAME MainTests COMMAND MainTests)