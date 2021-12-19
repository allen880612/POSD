#pragma once

#include <iostream>
// #include "./builder/shape_builder.h"

class ShapeBuilder;
class InputHandler {
public:
    void handle();

private:
    void printEditorInstructions();
    void handleEditorInstructions(int instruction);
    void save();
    void addCircle();
    void addRectangle();
    void addTriangle();
    void printCompoundInstructions();
    void handleCompoundInstructions(int instruction);
    void addCompound();

    ShapeBuilder* builder;
    bool isContinued = true;
};