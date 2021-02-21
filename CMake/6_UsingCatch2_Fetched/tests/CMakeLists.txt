
add_executable(MainTests
    mainTest.cpp
    MyProcessTests.cpp
)
target_link_libraries(MainTests PUBLIC
    Catch2::Catch2
	MainFrameComponent
)

add_test(NAME MainTests COMMAND MainTests)