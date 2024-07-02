#include "tests.h"

START_TEST(test_strstr_1) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "WoRld";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_2) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "\0";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_3) {
  char str1[] = "HElllllllo, WoRld!";
  char str2[] = "lllllllo";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_4) {
  char str1[] = "HElllllllo, WoRld!";
  char str2[] = "lllllo";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_5) {
  char str1[] = "1234567890987654321";
  char str2[] = "11";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_6) {
  char str1[] = "1234567890987654321";
  char str2[] = "1234";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_7) {
  char str1[] = "1234567890987654321";
  char str2[] = "4321";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_8) {
  char str1[] = "1234567890987654321";
  char str2[] = "89098";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_9) {
  char str1[] = "";
  char str2[] = "89098";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_10) {
  char str1[] = "1234567890987654321";
  char str2[] = "";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_11) {
  char str1[] = "FFFFF\n";
  char str2[] = "\n";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_12) {
  char str1[] = "FF\nFFF";
  char str2[] = "\n";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_13) {
  char str1[] = "123456FFFFFF";
  char str2[] = "FFFFFF";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_14) {
  char str1[] = "123456FFFFFF";
  char str2[] = "FFFFF";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_15) {
  char str1[] = "123456FFFFF";
  char str2[] = "FFFFFF";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

Suite *s21_strstr_suite(void) {
  Suite *s = suite_create("s21_strstr");
  TCase *tc = tcase_create("s21_strstr");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strstr_1);
  tcase_add_test(tc, test_strstr_2);
  tcase_add_test(tc, test_strstr_3);
  tcase_add_test(tc, test_strstr_4);
  tcase_add_test(tc, test_strstr_5);
  tcase_add_test(tc, test_strstr_6);
  tcase_add_test(tc, test_strstr_7);
  tcase_add_test(tc, test_strstr_8);
  tcase_add_test(tc, test_strstr_9);
  tcase_add_test(tc, test_strstr_10);
  tcase_add_test(tc, test_strstr_11);
  tcase_add_test(tc, test_strstr_12);
  tcase_add_test(tc, test_strstr_13);
  tcase_add_test(tc, test_strstr_14);
  tcase_add_test(tc, test_strstr_15);
  return s;
}
