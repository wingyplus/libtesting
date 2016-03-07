#ifndef TESTING_H_
#define TESTING_H_

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#define TEST(subject, name) static void test_##subject##_##name(void **state)

#define START_RUN_TESTS              \
  int main(int argc, char *argv[]) { \
  const struct CMUnitTest tests[] =

#define END_RUN_TESTS                               \
  ;                                                 \
  return cmocka_run_group_tests(tests, NULL, NULL); \
  }

#define TEST_ENTRY(subject, name) cmocka_unit_test(test_##subject##_##name),

#define EXPECT_STR_EQ(actual, expected) \
  assert_string_equal((actual), (expected))

#define EXPECT_INT_EQ(actual, expected) assert_int_equal((actual), (expected))

#define EXPECT_TRUE(expr) assert_true((expr))

#define EXPECT_FALSE(expr) assert_false((expr))

#endif /* TESTING_H_ */
