#include <iostream>
#include <fstream>
#include <sstream>
#include "IOHandler.h"
using namespace std;

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
    ofstream file(filePath);
    file << content;
    file.close();
}

// int main(int argc, char** argv) {
//     IOHandler io;
//     // cout << io.readFile("src/input/readFileTest.txt") << endl;
//     io.writeFile("src/output/outFileTest.txt", "outputTest");
//     return 1;
// }