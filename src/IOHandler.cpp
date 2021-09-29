#include <iostream>
#include <fstream>
#include <sstream>
#include "IOHandler.h"

string IOHandler::readFile(string filePath)
{
    auto ss = ostringstream();
    ifstream file;
    file.open(filePath);
    if (file.is_open())
    {
        ss << file.rdbuf();
        file.close();
        return ss.str();
    }
    else
    {
        cout << "File can't open!!" << endl;
        return "";
    }
}

void IOHandler::writeFile(string filePath, string content)
{
    
}

// int main(int argc, char** argv) {
//     IOHandler io;
//     cout << io.readFile("src/input/readFileTest.txt") << endl;
//     return 1;
// }