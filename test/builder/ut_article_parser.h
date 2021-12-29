#pragma once
#include "../../src/builder/shape_parser.h"
#include "../../src/compound_shape.h"
#include <cmath>

#define ACCURACY 0.001

// TEST(CaseParser, parseCircle) {
//     std::string path = "test/data/circle.txt";
//     ShapeParser parser(path);
//     double expectedArea = M_PI;
//     Shape* s = nullptr;
    
//     parser.parse();
//     s = parser.getShape();

//     ASSERT_EQ(typeid(Circle), typeid(*s));
//     ASSERT_NEAR(expectedArea, s->area(), ACCURACY);
//     delete s;
// }

// TEST(CaseParser, parseRectangle) {
//     std::string path = "test/data/rectangle.txt";
//     ShapeParser parser(path);
//     double expectedArea = 3.14 * 4.0;

//     parser.parse();
//     Shape* s = parser.getShape();

//     ASSERT_EQ(typeid(Rectangle), typeid(*s));
//     ASSERT_NEAR(expectedArea, s->area(), ACCURACY);
//     delete s;
// }

// TEST(CaseParser, parseTriangle) {
//     std::string path = "test/data/triangle.txt";
//     ShapeParser parser(path);
//     double expectedArea = 3 * 4 / 2;

//     parser.parse();
//     Shape* s = parser.getShape();

//     ASSERT_EQ(typeid(Triangle), typeid(*s));
//     ASSERT_NEAR(expectedArea, s->area(), ACCURACY);
//     delete s;
// }

// TEST(CaseParser, parseEmptyCompoundShape) {
//     std::string path = "test/data/empty_compound.txt";
//     ShapeParser parser(path);
//     double expectedArea = 0;

//     parser.parse();
//     Shape* s = parser.getShape();

//     ASSERT_EQ(typeid(CompoundShape), typeid(*s));
//     ASSERT_NEAR(expectedArea, s->area(), ACCURACY);

//     Iterator* it = s->createIterator();
//     ASSERT_TRUE(it->isDone());
//     delete it;
//     delete s;
// }

// TEST(CaseParser, parseCompoundShape) {
//     std::string path = "test/data/simple_compound.txt";
//     ShapeParser parser(path);
//     double expectedArea = M_PI + 3.14 * 4.0 + 3 * 4 / 2;

//     parser.parse();
//     Shape* s = parser.getShape();

//     ASSERT_EQ(typeid(CompoundShape), typeid(*s));
//     ASSERT_NEAR(expectedArea, s->area(), ACCURACY);

//     Iterator* it = s->createIterator();
//     ASSERT_FALSE(it->isDone());
//     delete it;
//     delete s;
// }

// TEST(CaseParser, parseComplexCompoundShape) {
//     std::string path = "test/data/complex_compound.txt";
//     ShapeParser parser(path);
//     double expectedArea = (M_PI + 3.14 * 4.0 + 3 * 4 / 2) * 2;

//     parser.parse();
//     Shape* s = parser.getShape();

//     ASSERT_EQ(typeid(CompoundShape), typeid(*s));
//     ASSERT_NEAR(expectedArea, s->area(), ACCURACY);

//     Iterator* it = s->createIterator();
//     ASSERT_FALSE(it->isDone());
//     delete it;
//     delete s;
// }

// TEST(CaseParser, parseNotExistFileShouldThrowException) {
//     std::string path = "NOT_EXIT_FILE";
//     ASSERT_ANY_THROW(ShapeParser parser(path));
// }