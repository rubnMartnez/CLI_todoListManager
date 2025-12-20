#include <gtest/gtest.h>

TEST(MathTest, Addition) {
    EXPECT_EQ(2 + 2, 4);
}

TEST(StringTest, Compare) {
    EXPECT_STREQ("hello", "hello");
}
