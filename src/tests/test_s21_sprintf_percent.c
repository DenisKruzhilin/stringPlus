#include <stdio.h>

#include "tests.h"

START_TEST(test_sprintf_percent_1) {
  char str_out1[50];
  char str_out2[50];
  char str_in[] = "HE%%o, WoR%%d%c!";
  int res1 = sprintf(str_out1, str_in, 'c');
  int res2 = s21_sprintf(str_out2, str_in, 'c');
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_percent_2) {
  char str_out1[50];
  char str_out2[50];
  char str_in[] = "HE%%%%o, WoR%%%%%%d%c!";
  int res1 = sprintf(str_out1, str_in, 'c');
  int res2 = s21_sprintf(str_out2, str_in, 'c');
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_percent_suite(void) {
  Suite *s = suite_create("s21_sprintf_percent");
  TCase *tc = tcase_create("s21_sprintf_percent");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_sprintf_percent_1);
  tcase_add_test(tc, test_sprintf_percent_2);
  return s;
}
