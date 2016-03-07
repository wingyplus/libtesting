#include <stdbool.h>
#include <testing.h>

TEST(matcher, expect_int_eq) { EXPECT_INT_EQ(1, 1); }

TEST(matcher, expect_str_eq) { EXPECT_STR_EQ("HELLO", "HELLO"); }

TEST(matcher, expect_false) {
  EXPECT_FALSE(false);
  EXPECT_FALSE(0);
  EXPECT_FALSE(1 == 0);
}

TEST(matcher, expect_true) {
  EXPECT_TRUE(true);
  EXPECT_TRUE(1);
  EXPECT_TRUE(1 == 1);
}

START_RUN_TESTS {
  TEST_ENTRY(matcher, expect_int_eq)
  TEST_ENTRY(matcher, expect_str_eq)
  TEST_ENTRY(matcher, expect_false)
  TEST_ENTRY(matcher, expect_true)
}
END_RUN_TESTS
