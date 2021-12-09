#pragma once
#include <string>
#include <vector>
#include <iostream>

class Scanner {
public:
    Scanner(std::string input) : _input(input) {}

    std::string next();
    double nextDouble();
    bool isDone();


private:
    void skipWhiteSpace();
    void skipNonToken();
    bool isDigitOrDot();
    const std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]", "{", "}", ","};
    std::string _input;
    std::string::size_type _pos = 0;
};

std::string Scanner::next() {
    if (_pos == _input.length()) {
        throw std::string("Already point to end of Input.");
    }
    std::string result = "";
    skipNonToken();
    if (_pos == _input.length()) {
        return nullptr;
    }
    for(auto token: tokenList) {
        if(_input.compare(_pos, token.length(), token) == 0) {
            _pos = _pos + token.length();
            result = token;
            return result;
        }
    }
}

void Scanner::skipNonToken() {
    while (_pos != _input.length()){
        for(auto token: tokenList) {
            if(_input.compare(_pos, token.length(), token) == 0)
                return;
        }
        _pos++;
    }
}

void Scanner::skipWhiteSpace() {
    while(_input[_pos] == ' ' || _input[_pos] == '\n' || _input[_pos] =='\t') {
        _pos++;
    }
}

bool Scanner::isDigitOrDot() {
    bool isEnd = _pos == _input.length();
    return  !isEnd && (_input[_pos] == '.' || _input[_pos] <= '9' && _input[_pos] >= '0');
}

double Scanner::nextDouble() {
    if (_pos == _input.length()) {
        throw std::string("Already point to end of Input.");
    }
    std::string s = "";
    while (!isDigitOrDot()) {
        _pos++;
    }
    while(isDigitOrDot()) {
        // twice or more dot will be an issue
        s = s + _input[_pos];
        _pos++;
    }
    return std::stod(s);
}

bool Scanner::isDone() {
    skipNonToken();
    return _pos == _input.length();
}