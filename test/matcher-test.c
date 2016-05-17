#include <stdbool.h>
#include <testing.h>

TEST(matcher, expect_int_eq) { EXPECT_INT_EQ(1, 1); }

TEST(matcher, expect_int_not_eq) { EXPECT_INT_NOT_EQ(1, 2); }

TEST(matcher, expect_str_eq) { EXPECT_STR_EQ("HELLO", "HELLO"); }

TEST(matcher, expect_str_not_eq) { EXPECT_STR_NOT_EQ("HELLO", "WORLD"); }

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

TEST(matcher, expect_ptr_eq) {
  int a = 1;
  int *b = &a, *c = &a;

  EXPECT_PTR_EQ(b, c);
}

TEST(matcher, expect_ptr_not_eq) {
  int a = 1, d = 2;
  int *b = &a, *c = &d;

  EXPECT_PTR_NOT_EQ(b, c);
}

START_RUN_TESTS {
  TEST_ENTRY(matcher, expect_int_eq)
  TEST_ENTRY(matcher, expect_int_not_eq)
  TEST_ENTRY(matcher, expect_str_eq)
  TEST_ENTRY(matcher, expect_str_not_eq)
  TEST_ENTRY(matcher, expect_false)
  TEST_ENTRY(matcher, expect_true)
  TEST_ENTRY(matcher, expect_ptr_eq)
  TEST_ENTRY(matcher, expect_ptr_not_eq)
}
END_RUN_TESTS
