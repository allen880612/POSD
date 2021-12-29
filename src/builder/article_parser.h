#pragma once
#include "../article.h"
#include "../builder/article_scanner.h"
#include "../builder/article_builder.h"
#include <fstream>
#include <sstream>
#include <iostream>

class ArticleParser {
public:
    // `filePath` is a relative path of makefile
    ArticleParser(std::string filePath) {
        _sc = new ArticleScanner(readFile(filePath));
        _builder = ArticleBuilder::getInstance();
    }

    ~ArticleParser() {
        delete _sc;
        _builder->reset();
    }
    void parse();
    Article* getArticle() { 
        Article* result = _builder->getArticle();
        _builder->reset();
        return result;
    }
private:
    std::string readFile(std::string filePath);
    ArticleBuilder* _builder;
    ArticleScanner* _sc;
};

std::string ArticleParser::readFile(std::string filePath) {
    auto ss = std::ostringstream();
    std::ifstream file;
    file.open(filePath);
    if (file.is_open()) {
        ss << file.rdbuf();
        file.close();
        return ss.str();
    }
    else {
        throw std::string("File can't open!!");
    }
}

void ArticleParser::parse() {
    while (!_sc->isDone()) {
        std::string token = _sc->nextToken();
        if (token == "ListItem") {
            _builder->buildListItem(_sc->nextStr());
        } else if (token == "Text") {
            _builder->buildText(_sc->nextStr());
        } else if (token == "Paragraph") {
            _builder->buildParagraphBegin(_sc->nextInt(), _sc->nextStr());
        } else if (token == "}") {
            _builder->buildParagraphEnd();
        }
    }
}
