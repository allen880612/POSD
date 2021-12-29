#pragma once
#include <string>
#include <list>
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

    std::string _input;
    const std::vector<std::string> tokenList = {"ListItem", "Text", "Paragraph", "(", ")", "{", "}"};
    std::list<std::string> tokens;
    std::list<std::string> strings;
    std::list<int> integers;

};

void ArticleScanner::buildTokens() {
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

void ArticleScanner::buildStrings() {
    std::string::size_type pos = 0;
    std::string str = "";
    bool isSaving = false;

    while (pos < _input.length()) {
        bool isQuote = _input[pos] == '\"';
        
        if(isQuote) {
            if (isSaving) {
                strings.push_back(str);
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
    if (str != "") 
        strings.push_back(str);
}

void ArticleScanner::buildIntegers() {
    std::string::size_type pos = 0;
    std::string numStr = "";

    while (pos < _input.length()) {
        bool isDigitOrDot = _input[pos] == '.' || _input[pos] <= '9' && _input[pos] >= '0';
        if(isDigitOrDot) {
            numStr += _input[pos];
        } else if (numStr != "") {
            integers.push_back(std::stod(numStr));
            numStr = "";
        }
        pos++;
    }
    // end of string
    if (numStr != "") integers.push_back(std::stod(numStr));
}

std::string ArticleScanner::nextToken() {
    if (isDone()) throw std::string("Already point to end of Input.");

    std::string result = tokens.front();
    tokens.pop_front();
    // std::cout << result << std::endl;
    return result;
}

std::string ArticleScanner::nextStr() {
    if (isDone()) throw std::string("Already point to end of Input.");

    std::string result = strings.front();
    strings.pop_front();
    // std::cout << result << std::endl;
    return result;
}

int ArticleScanner::nextInt() {
    if (isDone()) throw std::string("Already point to end of Input.");

    int result = integers.front();
    integers.pop_front();
    // std::cout << result << std::endl;
    return result;
}

bool ArticleScanner::isDone() {
    return tokens.empty() && integers.empty();
}