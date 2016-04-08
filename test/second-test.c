#include <stdbool.h>
#include <testing.h>

TEST(second, expect_int_eq) { EXPECT_INT_EQ(1, 1); }

TEST(second, expect_str_eq) { EXPECT_STR_EQ("HELLO", "WORLD"); }

TEST(second, expect_false) {
  EXPECT_FALSE(false);
  EXPECT_FALSE(0);
  EXPECT_FALSE(1 == 0);
}

TEST(second, expect_true) {
  EXPECT_TRUE(true);
  EXPECT_TRUE(1);
  EXPECT_TRUE(1 == 1);
}

START_RUN_TESTS {
  TEST_ENTRY(second, expect_int_eq)
  TEST_ENTRY(second, expect_str_eq)
  TEST_ENTRY(second, expect_false)
  TEST_ENTRY(second, expect_true)
}
END_RUN_TESTS
