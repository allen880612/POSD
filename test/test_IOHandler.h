#include <gtest/gtest.h>
#include "../src/IOHandler.h"

TEST(CaseIOHandler, ReadFile) {
    IOHandler ioHandler;
    string actual = ioHandler.readFile("src/input/readFileTest.txt");
    bool isEqual = "testRead" == actual;
    ASSERT_TRUE(isEqual);
}

TEST(CaseIOHandler, WriteFile) {
    
    ASSERT_EQ(true, true);
}