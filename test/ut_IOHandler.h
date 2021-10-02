#include <iostream>
#include <fstream>
#include <sstream>
#include "../src/IOHandler.h"

TEST(CaseIOHandler, ReadFile) {
    IOHandler ioHandler;

    string actual = ioHandler.readFile("src/input/readFileTest.txt");
    
    ASSERT_EQ("testRead", actual);
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
        ASSERT_EQ(expected == ss.str());
    }
    else
    {
        cout << "File can't open!!" << endl;
        __assert_fail;
    }
}