#include <iostream>
#include <vector>
#include <algorithm>
#include "circle.h"
using namespace std;


int main(int argc, char** argv) {
    vector<Circle*> v;
    // vector<int> v;
    for (int i = 0; i < 5; i++){
        v.push_back(new Circle(i));
    }
    std::sort(v.begin(), v.end(), [](Circle* n1, Circle* n2) 
    {
        return n1->area() >= n2->area();
    });
    
    for (Circle* n : v) {
        cout << n->area() << " ";
    }

    return 1;
}