#include "gtest/gtest.h"
#include "MyProcess.h"


TEST(TestToolChain, SimpleTest) {
    //arrange
    //act
    //assert

    EXPECT_EQ (0 , 0);
}

TEST(TestCase1, SimpleTest) {
    //arrange
    //act
    //assert
    uint32_t outVal;
    bool res = Pc_Evaluate(2, &outVal);

    EXPECT_EQ (false , res);
    EXPECT_EQ (4 , outVal);
}

TEST(TestCase2, SimpleTest) {
    //arrange
    //act
    //assert
    uint32_t outVal;
    bool res = Pc_Evaluate(4, &outVal);

    EXPECT_EQ (false , res);
    EXPECT_EQ (8 , outVal);
}

TEST(TestCase3, SimpleTest) {
    //arrange
    //act
    //assert
    uint32_t outVal;
    bool res = Pc_Evaluate(64, &outVal);

    EXPECT_EQ (true , res);
    EXPECT_EQ (100 , outVal);
}

TEST(ToFail, SimpleTest) {
    EXPECT_TRUE(false);
}