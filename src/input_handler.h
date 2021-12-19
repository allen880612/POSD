#pragma once

#include <iostream>
using namespace std;

class ShapeBuilder;
class InputHandler {
public:
    InputHandler();
    void handle();

private:
    void printEditorInstructions();
    void handleEditorInstructions(int instruction);
    void InputEditorInstruction();
    
    void addCircle();
    void addRectangle();
    void addTriangle();
    
    void printCompoundInstructions();
    void handleCompoundInstructions(int instruction);
    void InputCompoundInstruction();
    void addCompound();
    void endCompound();
    
    void save();
    void handleInvalidInput(string msg);

    ShapeBuilder* builder;
    bool isContinued = true;
};