#pragma once
#include <string>
#include <list>
#include <iostream>

class Scanner {
public:
    Scanner(std::string input) : _input(input) {
        buildTokens();
        buildDoubles();
    }

    std::string next();
    double nextDouble();
    bool isDone();


private:
    void buildTokens();
    void buildDoubles();

    std::string _input;
    const std::list<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]", "{", "}", ","};
    std::list<std::string> tokens;
    std::list<double> doubles;

};

void Scanner::buildTokens() {
    std::string::size_type pos = 0;

    while (pos < _input.length()) {
        bool isToken = false;
        for(auto token: tokenList) {
            isToken = _input.compare(pos, token.length(), token) == 0;
            if(isToken) {
                pos = pos + token.length();
                tokens.push_back(token);
                break;
            }
        }
        if (!isToken) pos++;
    }
}

void Scanner::buildDoubles() {
    std::string::size_type pos = 0;
    std::string numStr = "";

    while (pos < _input.length()) {
        bool isDigitOrDot = _input[pos] == '.' || _input[pos] <= '9' && _input[pos] >= '0';
        if(isDigitOrDot) {
            numStr += _input[pos];
        } else if (numStr != "") {
            doubles.push_back(std::stod(numStr));
            numStr = "";
        }
        pos++;
    }
    // end of string
    if (numStr != "") doubles.push_back(std::stod(numStr));
}

std::string Scanner::next() {
    if (isDone()) throw std::string("Already point to end of Input.");

    std::string result = tokens.front();
    tokens.pop_front();
    // std::cout << result << std::endl;
    return result;
}

double Scanner::nextDouble() {
    if (isDone()) throw std::string("Already point to end of Input.");

    double result = doubles.front();
    doubles.pop_front();
    // std::cout << result << std::endl;
    return result;
}

bool Scanner::isDone() {
    return tokens.empty() && doubles.empty();
}