#pragma
#include "../../src/builder/shape_parser.h"
#include "../../src/compound_shape.h"

TEST(CaseParser, parseCircle) {
    std::string path = "test/data/circle.txt";
    ShapeParser parser(path);
    parser.parse();
    Shape* shape = parser.getShape();
    ASSERT_TRUE(shape == nullptr);
}