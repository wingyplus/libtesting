#ifndef TESTING_H_
#define TESTING_H_

#include <stdbool.h>

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
  ({                                    \
    const char *a = actual;             \
    const char *e = expected;           \
    assert_string_equal((a), (e));      \
  })

#define EXPECT_INT_EQ(actual, expected) \
  ({                                    \
    int a = actual, e = expected;       \
    assert_int_equal((a), (e));         \
  })

#define EXPECT_TRUE(expr) \
  ({                      \
    bool e = expr;        \
    assert_true((e));     \
  })

#define EXPECT_FALSE(expr) \
  ({                       \
    bool e = expr;         \
    assert_false((e));     \
  })

#endif /* TESTING_H_ */
