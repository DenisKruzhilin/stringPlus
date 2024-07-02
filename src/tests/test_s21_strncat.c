#include "tests.h"

START_TEST(test_strncat_1) {
  char str1[] = "HEllo, WoRld!";
  char str2[30] = "olleh";
  char str3[30] = "olleh";
  s21_size_t n = 5;
  ck_assert_str_eq(strncat(str2, str1, n), s21_strncat(str3, str1, n));
}
END_TEST

START_TEST(test_strncat_2) {
  char str1[] = "HEllo, WoRld!";
  char str2[30] = "olleh";
  char str3[30] = "olleh";
  s21_size_t n = 0;
  ck_assert_str_eq(strncat(str2, str1, n), s21_strncat(str3, str1, n));
}
END_TEST

START_TEST(test_strncat_3) {
  char str1[] = "HEllo, WoRld!";
  char str2[30] = "olleh";
  char str3[30] = "olleh";
  s21_size_t n = 20;
  ck_assert_str_eq(strncat(str2, str1, n), s21_strncat(str3, str1, n));
}
END_TEST

START_TEST(test_strncat_4) {
  char str1[] = "798";
  char str2[30] = "123456789";
  char str3[30] = "123456789";
  s21_size_t n = 20;
  ck_assert_str_eq(strncat(str2, str1, n), s21_strncat(str3, str1, n));
}
END_TEST

START_TEST(test_strncat_5) {
  char str1[] = "798";
  char str2[30] = "123456789";
  char str3[30] = "123456789";
  s21_size_t n = 0;
  ck_assert_str_eq(strncat(str2, str1, n), s21_strncat(str3, str1, n));
}
END_TEST

START_TEST(test_strncat_6) {
  char str1[] = "798";
  char str2[30] = "123456789";
  char str3[30] = "123456789";
  s21_size_t n = 3;
  ck_assert_str_eq(strncat(str2, str1, n), s21_strncat(str3, str1, n));
}
END_TEST

START_TEST(test_strncat_7) {
  char str1[] = "HEllo, WoRld!";
  char str2[50] = "HEllo, WoRld";
  char str3[50] = "HEllo, WoRld";
  s21_size_t n = s21_strlen(str1);
  ck_assert_str_eq(strncat(str2, str1, n), s21_strncat(str3, str1, n));
}
END_TEST

Suite *s21_strncat_suite(void) {
  Suite *s = suite_create("s21_strncat");
  TCase *tc = tcase_create("s21_strncat");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strncat_1);
  tcase_add_test(tc, test_strncat_2);
  tcase_add_test(tc, test_strncat_3);
  tcase_add_test(tc, test_strncat_4);
  tcase_add_test(tc, test_strncat_5);
  tcase_add_test(tc, test_strncat_6);
  tcase_add_test(tc, test_strncat_7);

  return s;
}
