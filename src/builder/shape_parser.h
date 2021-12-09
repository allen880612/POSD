#pragma
#include "../shape.h"
#include "../builder/scanner.h"
#include "../builder/shape_builder.h"
#include <fstream>
#include <sstream>
#include <iostream>

class ShapeParser{
public:
    // `filePath` is a relative path of makefile
    ShapeParser(std::string filePath) {
        _sc = new Scanner(readFile(filePath));
        _builder = new ShapeBuilder();
    }

    ~ShapeParser() {
        delete _sc;
        delete _builder;
    }
    void parse();
    Shape* getShape() { return _builder->getShape(); }
private:
    std::string readFile(std::string filePath);
    ShapeBuilder* _builder;
    Scanner* _sc;
};

std::string ShapeParser::readFile(std::string filePath) {
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

void ShapeParser::parse() {
    while (!_sc->isDone()) {
        std::string token = _sc->next();
        if (token == "Circle") {
            _builder->buildCircle(_sc->nextDouble());
        } else if (token == "Rectangle") {
            _builder->buildRectangle(_sc->nextDouble(), _sc->nextDouble());
        } else if (token == "Triangle") {
            double x1 = _sc->nextDouble();
            double y1 = _sc->nextDouble();
            double x2 = _sc->nextDouble();
            double y2 = _sc->nextDouble();
            _builder->buildTriangle(x1, y1, x2, y2);
        } else if (token == "CompoundShape") {
            _builder->buildCompoundBegin();
        } else if (token == "}") {
            _builder->buildCompoundEnd();
        }
    }
}
