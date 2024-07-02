#include "tests.h"

START_TEST(test_s21_to_lower_1) {
  char str1[] = "HEllo, WoRld!";
  char* str2 = S21_NULL;
  char* res = "hello, world!";
  str2 = s21_to_lower(str1);
  ck_assert_str_eq(res, str2);
  free(str2);
}
END_TEST

START_TEST(test_s21_to_lower_2) {
  char str1[] = "HELLO, WORLD!!@#$%^&*()!;%:?*()_+-=";
  char* str2 = S21_NULL;
  char* res = "hello, world!!@#$%^&*()!;%:?*()_+-=";
  str2 = s21_to_lower(str1);
  ck_assert_str_eq(res, str2);
  free(str2);
}
END_TEST

START_TEST(test_s21_to_lower_3) {
  char str1[] = "";
  char* str2 = S21_NULL;
  char* res = "";
  str2 = s21_to_lower(str1);
  ck_assert_str_eq(res, str2);
  free(str2);
}
END_TEST

Suite* s21_to_lower_suite(void) {
  Suite* s = suite_create("s21_to_lower");
  TCase* tc = tcase_create("s21_to_lower");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_s21_to_lower_1);
  tcase_add_test(tc, test_s21_to_lower_2);
  tcase_add_test(tc, test_s21_to_lower_3);

  return s;
}
