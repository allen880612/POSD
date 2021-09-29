#include <string>
#include <iostream>
using namespace std;

class IOHandler
{
    public:
        IOHandler(){};
        void printTest() { cout << "pp" << endl; };
        string readFile(string filePath);
        void writeFile(string filePath, string content);

    private:
};