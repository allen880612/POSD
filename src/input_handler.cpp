#include <limits>
#include <fstream>
#include <sstream>

#include "input_handler.h"
#include "./builder/shape_parser.h"
#include "./visitor/shape_info_visitor.h"

#define ADD_CIRCLE 1
#define ADD_RECTANGLE 2
#define ADD_TRIANGLE 3
#define ADD_COMPOUND 4
#define SAVE 5
#define END_COMPOUND 5
#define EXIT 6

InputHandler::InputHandler() {
    builder = ShapeBuilder::getInstance();
}

void InputHandler::handle()
{
    do {
        printEditorInstructions();
        InputEditorInstruction();
    } while (isContinued);
    EXIT_SUCCESS;
}

void InputHandler::InputEditorInstruction() {
    int instruction = 0;
    cin >> instruction;
    if (cin) {
        handleEditorInstructions(instruction);
    }
    else {
        handleInvalidInput("Invalid instruction. Please try again");
    }
}

void InputHandler::handleInvalidInput(string msg) {
    cout << msg << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void InputHandler::printEditorInstructions() {
    cout << "Please enter the following instruction number number to start building:" << endl;
    cout << "  1. 'add circle': to add a circle" << endl;
    cout << "  2. 'add rectangle': to add a rectangle" << endl;
    cout << "  3. 'add triangle': to add a triangle" << endl;
    cout << "  4. 'add compound': to add a compound" << endl;
    cout << "  5. 'save': output shape to file" << endl;
    cout << "  6. 'exit': to exit the program" << endl;
}

void InputHandler::handleEditorInstructions(int instruction) {
    switch (instruction)
    {
    case ADD_CIRCLE:
        addCircle();
        break;

    case ADD_RECTANGLE:
        addRectangle();
        break;

    case ADD_TRIANGLE:
        addTriangle();
        break;

    case ADD_COMPOUND:
        addCompound();
        break;

    case SAVE:
        save();
        break;

    case EXIT:
        isContinued = false;
        break;

    default:
        cout << "Invalid instruction. Please try again." << endl;
        break;
    }
}

void InputHandler::save()
{
    Shape* savingShape = builder->getShape();
    ShapeInfoVisitor visitor;
    string savingResult = "";

    builder->reset();
    savingShape->accept(&visitor);
    savingResult = visitor.getResult();
    delete savingShape;

    cout << "Please enter the file name to save the shape:" << endl;
    string outputFileName = "";
    cin >> outputFileName;
    ofstream file(outputFileName);
    file << savingResult;
    file.close();

    cout << "Save complete." << endl;
}

void InputHandler::addCircle()
{
    double radius = 0;
    
    cout << "Please enter the information of circle:" << endl;
    cout << "Radius of circle: ";
    cin >> radius;
    
    if (!cin) {
        handleInvalidInput("Invalid argument. Please try again.");
        return;
    }

    try {
        builder->buildCircle(radius);
        cout << "Circle added." << endl;
    } catch (std::invalid_argument exception) {
        cout << "Invalid argument. Please try again." << endl;
    }
}

void InputHandler::addRectangle()
{
    double width = 0, height = 0;
    
    cout << "Please enter the information of rectangle:" << endl;
    cout << "Width of rectangle: ";
    cin >> width;
    cout << "Height of rectangle: ";
    cin >> height;

    if (!cin) {
        handleInvalidInput("Invalid argument. Please try again.");
        return;
    }

    try {
        builder->buildRectangle(height, width);
        cout << "Rectangle added." << endl;
    } catch (std::invalid_argument exception) {
        cout << "Invalid argument. Please try again." << endl;
    }
}

void InputHandler::addTriangle()
{
    double x1, y1, x2, y2;

    cout << "Please enter the information of triangle:" << endl;
    cout << "X1 of triangle: ";
    cin >> x1;
    cout << "Y1 of triangle: ";
    cin >> y1;
    cout << "X2 of triangle: ";
    cin >> x2;
    cout << "Y2 of triangle: ";
    cin >> y2;
    
    if (!cin) {
        handleInvalidInput("Invalid argument. Please try again.");
        return;
    }

    try {
        builder->buildTriangle(x1, y1, x2, y2);
        cout << "Triangle added." << endl;
    } catch (std::invalid_argument exception) {
        cout << "Invalid argument. Please try again." << endl;
    }
}

void InputHandler::printCompoundInstructions()
{
    cout << "Please enter the following instruction number to build the compound:" << endl;
    cout << "1. 'add circle': to add a circle" << endl;
    cout << "2. 'add rectangle': to add a rectangle" << endl;
    cout << "3. 'add triangle': to add a triangle" << endl;
    cout << "4. 'add compound': to add a compound" << endl;
    cout << "5. 'end building compound': to build a compound" << endl;
}

void InputHandler::handleCompoundInstructions(int instruction)
{
    switch (instruction)
    {
    case ADD_CIRCLE:
        addCircle();
        break;

    case ADD_RECTANGLE:
        addRectangle();
        break;

    case ADD_TRIANGLE:
        addTriangle();
        break;

    case ADD_COMPOUND:
        addCompound();
        break;

    case END_COMPOUND:
        endCompound();
        break;

    default:
        cout << "Invalid instruction. Please try again." << endl;
        break;
    }
}

void InputHandler::addCompound()
{
    builder->buildCompoundBegin();
    InputCompoundInstruction();
}

void InputHandler::endCompound()
{
    builder->buildCompoundEnd();
    cout << "Compound added." << endl;
}

void InputHandler::InputCompoundInstruction() {
    int instruction = 0;
    
    do {
        printCompoundInstructions();
        cin >> instruction;
        if (cin) {
            handleCompoundInstructions(instruction);
        }
        else {
            // not integer
            handleInvalidInput("Invalid instruction. Please try again.");
        }
    } while (instruction != END_COMPOUND);
}