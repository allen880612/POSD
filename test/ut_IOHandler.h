#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../src/IOHandler.h"

TEST(CaseIOHandler, ReadFile) {
    IOHandler ioHandler;
    string actual = ioHandler.readFile("src/input/readFileTest.txt");
    bool isEqual = "testRead" == actual;
    ASSERT_TRUE(isEqual);
}

TEST(CaseIOHandler, WriteFile) {
    IOHandler ioHandler;
    const string outputFilePath = "src/output/readFileTest.txt";
    const string expected = "outputTest";

    ioHandler.writeFile(outputFilePath, expected);

    auto ss = ostringstream();
    ifstream file;
    file.open(outputFilePath);
    if (file.is_open())
    {
        ss << file.rdbuf();
        file.close();
        bool isEqual = expected == ss.str();
        ASSERT_TRUE(isEqual);
    }
    else
    {
        cout << "File can't open!!" << endl;
        __assert_fail;
    }
}