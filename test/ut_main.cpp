#include <gtest/gtest.h>
#include "ut_circle.h"
#include "ut_rectangle.h"
#include "ut_shape.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// TEST(Sanity, First) { ASSERT_TRUE(true); }