#include "tests.h"

START_TEST(test_strncpy_1) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "olleh";
  char str3[] = "olleh";
  s21_size_t n = 5;
  ck_assert_str_eq(strncpy(str2, str1, n), s21_strncpy(str3, str1, n));
}
END_TEST

START_TEST(test_strncpy_2) {
  char str1[] = "HEllo, WoRld!";
  char str2[40] = "olleh";
  char str3[40] = "olleh";
  s21_size_t n = 6;
  ck_assert_str_eq(strncpy(str2, str1, n), s21_strncpy(str3, str1, n));
}
END_TEST

START_TEST(test_strncpy_3) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "olleh";
  char str3[] = "olleh";
  s21_size_t n = 0;
  ck_assert_str_eq(strncpy(str2, str1, n), s21_strncpy(str3, str1, n));
}
END_TEST

START_TEST(test_strncpy_4) {
  char str1[] = "HEllo, WoRld!";
  char str2[40] = "olleh";
  char str3[40] = "olleh";
  s21_size_t n = 15;
  ck_assert_str_eq(strncpy(str2, str1, n), s21_strncpy(str3, str1, n));
}
END_TEST

START_TEST(test_strncpy_5) {
  char str1[20] = "olleh";
  char str2[20] = "HEllo, WoRld!";
  char str3[20] = "HEllo, WoRld!";
  s21_size_t n = 15;
  ck_assert_str_eq(strncpy(str2, str1, n), s21_strncpy(str3, str1, n));
}
END_TEST

START_TEST(test_strncpy_6) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld";
  char str3[] = "HEllo, WoRld";

  s21_size_t n = s21_strlen(str2);
  ck_assert_str_eq(strncpy(str2, str1, n), s21_strncpy(str3, str1, n));
}
END_TEST

START_TEST(test_strncpy_7) {
  char str1[] = "HEllo, WoRld!";
  char str2[40] = "HEllo, WoRld";
  char str3[40] = "HEllo, WoRld";
  s21_size_t n = s21_strlen(str1);
  ck_assert_str_eq(strncpy(str2, str1, n), s21_strncpy(str3, str1, n));
}
END_TEST

START_TEST(test_strncpy_8) {
  char str1[] = "1234567890987654321";
  char str2[] = "HEllo, WoRld";
  char str3[] = "HEllo, WoRld";
  s21_size_t n = 0;
  ck_assert_str_eq(strncpy(str2, str1, n), s21_strncpy(str3, str1, n));
}
END_TEST

START_TEST(test_strncpy_9) {
  char str1[] = "1234567890987654321";
  char str2[] = "HEllo, WoRld";
  char str3[] = "HEllo, WoRld";
  s21_size_t n = 3;
  ck_assert_str_eq(strncpy(str2, str1, n), s21_strncpy(str3, str1, n));
}
END_TEST

START_TEST(test_strncpy_10) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld";
  char str3[] = "HEllo, WoRld";
  s21_size_t n = s21_strlen(str2);
  ck_assert_str_eq(strncpy(str2, str1, n), s21_strncpy(str3, str1, n));
}
END_TEST

START_TEST(test_strncpy_11) {
  char str1[] = "987654";
  char str2[] = "123456789";
  char str3[] = "123456789";
  s21_size_t n = s21_strlen(str1);
  ck_assert_str_eq(strncpy(str2, str1, n), s21_strncpy(str3, str1, n));
}
END_TEST

START_TEST(test_strncpy_12) {
  char str1[] = "987654";
  char str2[] = "123456789";
  char str3[] = "123456789";
  s21_size_t n = s21_strlen(str2);
  ck_assert_str_eq(strncpy(str2, str1, n), s21_strncpy(str3, str1, n));
}
END_TEST

Suite *s21_strncpy_suite(void) {
  Suite *s = suite_create("s21_strncpy");
  TCase *tc = tcase_create("s21_strncpy");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strncpy_1);
  tcase_add_test(tc, test_strncpy_2);
  tcase_add_test(tc, test_strncpy_3);
  tcase_add_test(tc, test_strncpy_4);
  tcase_add_test(tc, test_strncpy_5);
  tcase_add_test(tc, test_strncpy_6);
  tcase_add_test(tc, test_strncpy_7);
  tcase_add_test(tc, test_strncpy_8);
  tcase_add_test(tc, test_strncpy_9);
  tcase_add_test(tc, test_strncpy_10);
  tcase_add_test(tc, test_strncpy_11);
  tcase_add_test(tc, test_strncpy_12);
  return s;
}
