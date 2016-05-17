#ifndef TESTING_H_
#define TESTING_H_

#include <stdbool.h>

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#define TEST(subject, name) static void test_##subject##_##name(void **state)
#define SETUP(subject, name) static int setup_##subject##_##name(void **state)
#define TEARDOWN(subject, name) static int teardown_##subject##_##name(void **state)

#define START_RUN_TESTS              \
  int main(int argc, char *argv[]) { \
  const struct CMUnitTest tests[] =

#define END_RUN_TESTS                               \
  ;                                                 \
  return cmocka_run_group_tests(tests, NULL, NULL); \
  }

#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define TEST_ENTRY(...) GET_MACRO(__VA_ARGS__, TEST_ENTRY_WITH_SETUP_TEAR_DOWN, TEST_ENTRY_WITH_SETUP, TEST_ENTRY_WITHOUT_SETUP_TEARDOWN)(__VA_ARGS__)
#define TEST_ENTRY_WITHOUT_SETUP_TEARDOWN(subject, name) cmocka_unit_test(test_##subject##_##name),
#define TEST_ENTRY_WITH_SETUP(subject, name, setup) cmocka_unit_test_setup(test_##subject##_##name, setup_##subject##_##name),
#define TEST_ENTRY_WITH_SETUP_TEAR_DOWN(subject, name, setup, teardown) cmocka_unit_test_setup_teardown(test_##subject##_##name, setup_##subject##_##setup, teardown_##subject##_##teardown),

#define EXPECT_STR_EQ(actual, expected) \
  ({                                    \
    const char *a = actual;             \
    const char *e = expected;           \
    assert_string_equal((a), (e));      \
  })

#define EXPECT_STR_NOT_EQ(actual, expected) \
  ({                                        \
    const char *a = actual;                 \
    const char *e = expected;               \
    assert_string_not_equal((a), (e));      \
  })

#define EXPECT_INT_EQ(actual, expected) \
  ({                                    \
    int a = actual, e = expected;       \
    assert_int_equal((a), (e));         \
  })

#define EXPECT_INT_NOT_EQ(actual, expected) \
  ({                                        \
    int a = actual, e = expected;           \
    assert_int_not_equal((a), (e));         \
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

#define EXPECT_PTR_EQ(p1, p2) ({ assert_ptr_equal(p1, p2); })

#define EXPECT_PTR_NOT_EQ(p1, p2) ({ assert_ptr_not_equal(p1, p2); })

#endif /* TESTING_H_ */
