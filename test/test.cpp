#include <gtest/gtest.h>
#include "test_square.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// TEST(Sanity, First) { ASSERT_TRUE(true); }