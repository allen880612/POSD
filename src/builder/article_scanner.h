#pragma once
#include <string>
#include <list>
#include <utility>
#include <iostream>

class ArticleScanner {
public:
    ArticleScanner(std::string input) : _input(input) {
        buildTokens();
        buildStrings();
        buildIntegers();
    }

    std::string nextToken();
    std::string nextStr();
    int nextInt();
    bool isDone();


private:
    void buildTokens();
    void buildStrings();
    void buildIntegers();
    void updatePos();

    std::string _input = "";
    std::string::size_type _pos = 0;
    const std::vector<std::string> tokenList = {"ListItem", "Text", "Paragraph", "(", ")", "{", "}"};
    std::list<std::pair<std::string::size_type, std::string>> tokens;
    std::list<std::pair<std::string::size_type, std::string>> strings;
    std::list<std::pair<std::string::size_type, int>> integers;

};

void ArticleScanner::buildTokens() {
    std::string::size_type pos = 0;

    while (pos < _input.length()) {
        bool isToken = false;
        for(auto token: tokenList) {
            isToken = _input.compare(pos, token.length(), token) == 0;
            if(isToken) {
                tokens.push_back(std::make_pair(pos, token));
                pos = pos + token.length();
                // tokens.push_back(token);
                break;
            }
        }
        if (!isToken) pos++;
    }
}

void ArticleScanner::buildStrings() {
    std::string::size_type pos = 0;
    std::string str = "";
    bool isSaving = false;

    while (pos < _input.length()) {
        bool isQuote = _input[pos] == '\"';
        
        if(isQuote) {
            if (isSaving) {
                strings.push_back(std::make_pair(pos-str.length(), str));
                str = "";
            }
            isSaving = !isSaving;
        } 
        else if (isSaving) {
            str += _input[pos];
        }
        pos++;
    }
    // end of string
    if (str != "") {
        strings.push_back(std::make_pair(pos - str.length(), str));
    }
}

void ArticleScanner::buildIntegers() {
    std::string::size_type pos = 0;
    std::string numStr = "";

    while (pos < _input.length()) {
        bool isDigitOrDot = _input[pos] == '.' || _input[pos] <= '9' && _input[pos] >= '0';
        if(isDigitOrDot) {
            numStr += _input[pos];
        } else if (numStr != "") {
            integers.push_back(std::make_pair(pos - numStr.length(), std::stod(numStr)));
            numStr = "";
        }
        pos++;
    }
    // end of string
    if (numStr != "") integers.push_back(std::make_pair(pos - numStr.length(), std::stod(numStr)));
}

void ArticleScanner::updatePos() {
    std::cout << "cur Pos" << _pos << std::endl;
    while (!tokens.empty() && tokens.front().first < _pos) {
        std::cout << "remove" << tokens.front().first << tokens.front().second << std::endl;
        tokens.pop_front();
    }

    while (!strings.empty() && strings.front().first < _pos) {
        std::cout << "remove" << strings.front().first << strings.front().second << std::endl;
        strings.pop_front();
    }

    while (!integers.empty() && integers.front().first < _pos) {
        std::cout << "remove" << integers.front().first << integers.front().second << std::endl;
        integers.pop_front();
    }
}

std::string ArticleScanner::nextToken() {
    if (isDone()) throw std::string("Already point to end of Input.");

    std::string result = tokens.front().second;
    _pos = tokens.front().first;
    tokens.pop_front();
    // updatePos();

    // std::cout << "sc " << result << std::endl;
    return result;
}

std::string ArticleScanner::nextStr() {
    if (isDone()) throw std::string("Already point to end of Input.");

    std::string result = strings.front().second;
    _pos = strings.front().first;
    strings.pop_front();
    // updatePos();
    // std::cout << "sc " <<result << std::endl;
    return result;
}

int ArticleScanner::nextInt() {
    if (isDone()) throw std::string("Already point to end of Input.");

    int result = integers.front().second;
    _pos = integers.front().first;
    integers.pop_front();
    // updatePos();
    // std::cout << "sc " << result << std::endl;
    return result;
}

bool ArticleScanner::isDone() {
    return tokens.empty() && integers.empty() && strings.empty();
}