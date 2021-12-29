#pragma once
#include "../../src/builder/scanner.h"

#define ACCURACY 0.001

// TEST(CaseScanner, scanCircle) {
//     std::string input = "Circle (3.14159)";
//     Scanner sc(input);

//     ASSERT_EQ("Circle", sc.next());
//     ASSERT_EQ("(", sc.next());
//     ASSERT_NEAR(3.14159, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ(")", sc.next());
//     ASSERT_TRUE(sc.isDone());
// }

// TEST(CaseScanner, scanCircleWithNoise) {
//     std::string input = "I Circle eee ,tt{t3.14159a";
//     Scanner sc(input);

//     ASSERT_EQ("Circle", sc.next());
//     ASSERT_EQ(",", sc.next());
//     ASSERT_EQ("{", sc.next());
//     ASSERT_NEAR(3.14159, sc.nextDouble(), ACCURACY);
//     ASSERT_TRUE(sc.isDone());
// }

// TEST(CaseScanner, scanRectangle) {
//     std::string input = "Rectangle (3.14 4.0)";
//     Scanner sc(input);

//     ASSERT_EQ("Rectangle", sc.next());
//     ASSERT_EQ("(", sc.next());
//     ASSERT_NEAR(3.14, sc.nextDouble(), ACCURACY);
//     ASSERT_NEAR(4.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ(")", sc.next());
//     ASSERT_TRUE(sc.isDone());
// }

// TEST(CaseScanner, scanRectangleWithNoise) {
//     std::string input = "!@ RectangleD, G3.14ZZ4.0 d";
//     Scanner sc(input);

//     ASSERT_EQ("Rectangle", sc.next());
//     ASSERT_EQ(",", sc.next());
//     ASSERT_NEAR(3.14, sc.nextDouble(), ACCURACY);
//     ASSERT_NEAR(4.0, sc.nextDouble(), ACCURACY);
//     ASSERT_TRUE(sc.isDone());
// }

// TEST(CaseScanner, scanTriangle) {
//     std::string input = "Triangle ([3.0 0.0] [0.0 4.0])";
//     Scanner sc(input);

//     ASSERT_EQ("Triangle", sc.next());
//     ASSERT_EQ("(", sc.next());
//     ASSERT_EQ("[", sc.next());
//     ASSERT_NEAR(3.0, sc.nextDouble(), ACCURACY);
//     ASSERT_NEAR(0.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ("]", sc.next());
//     ASSERT_EQ("[", sc.next());
//     ASSERT_NEAR(0.0, sc.nextDouble(), ACCURACY);
//     ASSERT_NEAR(4.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ("]", sc.next());
//     ASSERT_EQ(")", sc.next());
//     ASSERT_TRUE(sc.isDone());
// }

// TEST(CaseScanner, scanTriangleWithNoise) {
//     std::string input = "AUAUTriangle (d [3.0 peko 0.0] [0.0 hihi 4.0] D)D";
//     Scanner sc(input);

//     ASSERT_EQ("Triangle", sc.next());
//     ASSERT_EQ("(", sc.next());
//     ASSERT_EQ("[", sc.next());
//     ASSERT_NEAR(3.0, sc.nextDouble(), ACCURACY);
//     ASSERT_NEAR(0.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ("]", sc.next());
//     ASSERT_EQ("[", sc.next());
//     ASSERT_NEAR(0.0, sc.nextDouble(), ACCURACY);
//     ASSERT_NEAR(4.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ("]", sc.next());
//     ASSERT_EQ(")", sc.next());
//     ASSERT_TRUE(sc.isDone());
// }

// TEST(CaseScanner, scanEmptyCompoundShape) {
//     std::string input = "CompoundShape {}";
//     Scanner sc(input);

//     ASSERT_EQ("CompoundShape", sc.next());
//     ASSERT_EQ("{", sc.next());
//     ASSERT_EQ("}", sc.next());
//     ASSERT_TRUE(sc.isDone());
// }

// TEST(CaseScanner, scanEmptyCompoundShapeWithNoise) {
//     std::string input = "CompoundShape Circular{SELECT*FROM USER WHERE 1;--}recursion";
//     Scanner sc(input);

//     ASSERT_EQ("CompoundShape", sc.next());
//     ASSERT_EQ("{", sc.next());
//     ASSERT_NEAR(1.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ("}", sc.next());
//     ASSERT_TRUE(sc.isDone());
// }

// TEST(CaseScanner, scanComplexCompoundShape) {
//     std::string input = "CompoundShape {"
//                         "Circle (1.0)"
//                         "Triangle ([3,0] [0,4])"
//                         "CompoundShape {"
//                             "Circle (1.0)"
//                             "Rectangle (3.14 4.00)"
//                             "Triangle ([3,0] [0,4])"
//                         "}"
//                         "Rectangle (3.14 4.00)"
//                         "}";
//     Scanner sc(input);

//     ASSERT_EQ("CompoundShape", sc.next());
//     ASSERT_EQ("{", sc.next());
//     ASSERT_EQ("Circle", sc.next());
//     ASSERT_EQ("(", sc.next());
//     ASSERT_NEAR(1.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ(")", sc.next());
//     ASSERT_EQ("Triangle", sc.next());
//     ASSERT_EQ("(", sc.next());
//     ASSERT_EQ("[", sc.next());
//     ASSERT_NEAR(3.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ(",", sc.next());
//     ASSERT_NEAR(0.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ("]", sc.next());
//     ASSERT_EQ("[", sc.next());
//     ASSERT_NEAR(0.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ(",", sc.next());
//     ASSERT_NEAR(4.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ("]", sc.next());
//     ASSERT_EQ(")", sc.next());
//     ASSERT_EQ("CompoundShape", sc.next());
//     ASSERT_EQ("{", sc.next());
//     ASSERT_EQ("Circle", sc.next());
//     ASSERT_EQ("(", sc.next());
//     ASSERT_NEAR(1.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ(")", sc.next());
//     ASSERT_EQ("Rectangle", sc.next());
//     ASSERT_EQ("(", sc.next());
//     ASSERT_NEAR(3.14, sc.nextDouble(), ACCURACY);
//     ASSERT_NEAR(4.00, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ(")", sc.next());
//     ASSERT_EQ("Triangle", sc.next());
//     ASSERT_EQ("(", sc.next());
//     ASSERT_EQ("[", sc.next());
//     ASSERT_NEAR(3.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ(",", sc.next());
//     ASSERT_NEAR(0.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ("]", sc.next());
//     ASSERT_EQ("[", sc.next());
//     ASSERT_NEAR(0.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ(",", sc.next());
//     ASSERT_NEAR(4.0, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ("]", sc.next());
//     ASSERT_EQ(")", sc.next());
//     ASSERT_EQ("}", sc.next());
//     ASSERT_EQ("Rectangle", sc.next());
//     ASSERT_EQ("(", sc.next());
//     ASSERT_NEAR(3.14, sc.nextDouble(), ACCURACY);
//     ASSERT_NEAR(4.00, sc.nextDouble(), ACCURACY);
//     ASSERT_EQ(")", sc.next());
//     ASSERT_EQ("}", sc.next());
//     ASSERT_TRUE(sc.isDone());
// }

// TEST(CaseScanner, callNextShouldThrowExceptionWhileAlreadyDone) {
//     std::string input = "";
//     Scanner sc(input);

//     ASSERT_TRUE(sc.isDone());
//     ASSERT_ANY_THROW(sc.next());
// }

// TEST(CaseScanner, callNextDoubleShouldThrowExceptionWhileAlreadyDone) {
//     std::string input = "";
//     Scanner sc(input);

//     ASSERT_TRUE(sc.isDone());
//     ASSERT_ANY_THROW(sc.nextDouble());
// }

// TEST(CaseScanner, isDoneTest) {
//     std::string input = "Circle 12.156";
//     Scanner sc(input);

//     sc.next();
//     ASSERT_FALSE(sc.isDone());
//     ASSERT_NEAR(12.156, sc.nextDouble(), ACCURACY);
//     ASSERT_TRUE(sc.isDone());
// }