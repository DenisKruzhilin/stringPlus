#include "tests.h"

START_TEST(test_strerror_1) {
  for (int i = 0; i < 140; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(test_strerror_2) {
  ck_assert_str_eq(strerror(-1), s21_strerror(-1));
}
END_TEST

Suite *s21_strerror_suite(void) {
  Suite *s = suite_create("s21_strerror");
  TCase *tc = tcase_create("s21_strerror");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strerror_1);
  tcase_add_test(tc, test_strerror_2);

  return s;
}
