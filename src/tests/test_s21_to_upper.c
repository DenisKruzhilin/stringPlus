#include "tests.h"

START_TEST(test_to_upper_1) {
  char str1[] = "HEllo, WoRld!";
  char* str2 = S21_NULL;
  char* res = "HELLO, WORLD!";
  str2 = s21_to_upper(str1);
  ck_assert_str_eq(res, str2);
  free(str2);
}
END_TEST

START_TEST(test_to_upper_2) {
  char str1[] = "hello, world!!@#$%^&*()!;%:?*()_+-=";
  char* str2 = S21_NULL;
  char* res = "HELLO, WORLD!!@#$%^&*()!;%:?*()_+-=";
  str2 = s21_to_upper(str1);
  ck_assert_str_eq(res, str2);
  free(str2);
}
END_TEST

START_TEST(test_to_upper_3) {
  char str1[] = "";
  char* str2 = S21_NULL;
  char* res = "";
  str2 = s21_to_upper(str1);
  ck_assert_str_eq(res, str2);
  free(str2);
}
END_TEST

Suite* s21_to_upper_suite(void) {
  Suite* s = suite_create("s21_to_upper");
  TCase* tc = tcase_create("s21_to_upper");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_to_upper_1);
  tcase_add_test(tc, test_to_upper_2);
  tcase_add_test(tc, test_to_upper_3);

  return s;
}