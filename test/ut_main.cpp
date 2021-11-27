#include <gtest/gtest.h>

#include "ut_shape.h"
#include "ut_circle.h"
#include "ut_rectangle.h"
#include "ut_triangle.h"
#include "ut_two_dimensional_vector.h"

#include "ut_iterator.h"
#include "ut_compound_shape.h"
#include "ut_utility.h"
#include "ut_visitor.h"


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
