add_executable(MyTests testMain.cpp MyProcessTest.cpp)
target_link_libraries(MyTests PUBLIC MainFrameComponent gtest)

add_test ( NAME MyTests COMMAND MyTests ) 