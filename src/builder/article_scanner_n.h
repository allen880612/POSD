#pragma once
#include <string>
#include <list>
#include <utility>
#include <iostream>

class ArticleScanner {
public:
    ArticleScanner(std::string input) : _input(input) {
    }

    std::string nextToken();
    std::string nextStr();
    int nextInt();
    bool isDone();

private:
    void skipWhiteSpace();
    void skipNonToken();
    bool isDigitOrDot();
    std::string _input = "";
    std::string::size_type _pos = 0;
    const std::vector<std::string> tokenList = {"ListItem", "Text", "Paragraph", "(", ")", "{", "}"};

};

// void ArticleScanner::buildTokens() {

//     while (_pos < _input.length()) {
//         bool isToken = false;
//         for(auto token: tokenList) {
//             isToken = _input.compare(_pos, token.length(), token) == 0;
//             if(isToken) {
//                 tokens.push_back(std::make_pair(_pos, token));
//                 _pos = _pos + token.length();
//                 // tokens.push_back(token);
//                 break;
//             }
//         }
//         if (!isToken) _pos++;
//     }
// }

// void ArticleScanner::buildStrings() {
//     std::string::size_type _pos = 0;
//     std::string str = "";
//     bool isSaving = false;

//     while (_pos < _input.length()) {
//         bool isQuote = _input[_pos] == '\"';
        
//         if(isQuote) {
//             if (isSaving) {
//                 strings.push_back(std::make_pair(_pos-str.length(), str));
//                 str = "";
//             }
//             isSaving = !isSaving;
//         } 
//         else if (isSaving) {
//             str += _input[_pos];
//         }
//         _pos++;
//     }
//     // end of string
//     if (str != "") {
//         strings.push_back(std::make_pair(_pos - str.length(), str));
//     }
// }

// void ArticleScanner::buildIntegers() {
//     std::string::size_type _pos = 0;
//     std::string numStr = "";

//     while (_pos < _input.length()) {
//         bool isDigitOrDot = _input[_pos] == '.' || _input[_pos] <= '9' && _input[_pos] >= '0';
//         if(isDigitOrDot) {
//             numStr += _input[_pos];
//         } else if (numStr != "") {
//             integers.push_back(std::make_pair(_pos - numStr.length(), std::stod(numStr)));
//             numStr = "";
//         }
//         _pos++;
//     }
//     // end of string
//     if (numStr != "") integers.push_back(std::make_pair(_pos - numStr.length(), std::stod(numStr)));
// }

void ArticleScanner::skipWhiteSpace() {
    while(_pos < _input.length()) {
        if (_input[_pos] == ' ' || _input[_pos] == '\n' || _input[_pos] =='\t') {
            _pos++;
        }
    }
}

void ArticleScanner::skipNonToken() {
    while (_pos < _input.length()){
        for(auto token: tokenList) {
            if(_input.compare(_pos, token.length(), token) == 0)
                return;
        }
        _pos++;
    }
}

std::string ArticleScanner::nextToken() {
    if (isDone()) throw std::string("Already point to end of Input.");
    
    std::string result = "";
    skipNonToken();

    for(auto token: tokenList) {
        if(_input.compare(_pos, token.length(), token) == 0) {
            _pos = _pos + token.length();
            result = token;
            break;
        }
    }

    std::cout << "sc " << result << std::endl;
    return result;
}

std::string ArticleScanner::nextStr() {
    if (isDone()) throw std::string("Already point to end of Input.");

    std::string result = "";
    bool isSaving = false;

    while (_pos < _input.length()) {

        if (_pos == _input.length()) {
            throw std::string("Already point to end of Input.");
        }

        bool isQuote = _input[_pos] == '\"';
        
        if(isQuote) {
            if (isSaving) {
                break;
            }
            isSaving = !isSaving;
        } 
        else if (isSaving) {
            result += _input[_pos];
        }
        _pos++;
    }

    std::cout << "sc " << result << std::endl;
    return result;
}

bool ArticleScanner::isDigitOrDot() {
    bool isEnd = _pos == _input.length();
    return  !isEnd && (_input[_pos] == '.' || _input[_pos] <= '9' && _input[_pos] >= '0');
}

int ArticleScanner::nextInt() {
    if (isDone()) throw std::string("Already point to end of Input.");

    std::string numStr = "";
    std::string result = "";

    while (!isDigitOrDot()) {
        if (_pos == _input.length()) {
            throw std::string("Already point to end of Input.");
        }
        _pos++;
    }

    while(isDigitOrDot()) {
        // twice or more dot will be an issue
        numStr += _input[_pos];
        _pos++;
    }


    while (_pos < _input.length()) {
        bool isDigitOrDot = _input[_pos] == '.' || _input[_pos] <= '9' && _input[_pos] >= '0';
        if(isDigitOrDot) {
            numStr += _input[_pos];
        } else if (numStr != "") {
            result = numStr;
            break;   
        }
        _pos++;
    }

    // end of string
    if (numStr != "") 
        result = numStr;

    std::cout << "sc " << result << std::endl;    
    
    return std::stod(result);
}

bool ArticleScanner::isDone() {
    skipNonToken();
    return _pos == _input.length();
}