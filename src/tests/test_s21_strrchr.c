#include "tests.h"

START_TEST(test_strrchr_1) {
  char str1[] = "HEllo, WoRld!";
  int chr = 'o';
  ck_assert_str_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

START_TEST(test_strrchr_2) {
  char str1[] = "12222222222222222222";
  int chr = '1';
  ck_assert_str_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

START_TEST(test_strrchr_3) {
  char str1[] = "HEllo, WoRld!";
  int chr = '!';
  ck_assert_str_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

START_TEST(test_strrchr_4) {
  char str1[] = "HEllo, WoRld!";
  int chr = 'H';
  ck_assert_str_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

START_TEST(test_strrchr_5) {
  char str1[] = "HEllo, WoRld!";
  int chr = '8';
  ck_assert_ptr_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

START_TEST(test_strrchr_6) {
  char str1[] = "12222222222222222222";
  int chr = '2';
  ck_assert_str_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

START_TEST(test_strrchr_7) {
  char str1[] = "12222222222222222222";
  int chr = '3';
  ck_assert_ptr_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

START_TEST(test_strrchr_8) {
  char str1[] = "12222222222\n2222111111";
  int chr = '3';
  ck_assert_ptr_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

START_TEST(test_strrchr_9) {
  char str1[] = "12222222222\n2222111111";
  int chr = '2';
  ck_assert_str_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

START_TEST(test_strrchr_10) {
  char str1[] = "12222222222\n2222111111";
  int chr = '1';
  ck_assert_str_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

START_TEST(test_strrchr_11) {
  char str1[] = "12222222222\n2222111111";
  int chr = '\0';
  ck_assert_str_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

START_TEST(test_strrchr_12) {
  char str1[] = "";
  int chr = '\0';
  ck_assert_str_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

START_TEST(test_strrchr_13) {
  char str1[] = "";
  int chr = '1';
  ck_assert_ptr_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

START_TEST(test_strrchr_14) {
  char str1[] = "";
  int chr = 'H';
  ck_assert_ptr_eq(strrchr(str1, chr), s21_strrchr(str1, chr));
}
END_TEST

Suite *s21_strrchr_suite(void) {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc = tcase_create("s21_strrchr");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strrchr_1);
  tcase_add_test(tc, test_strrchr_2);
  tcase_add_test(tc, test_strrchr_3);
  tcase_add_test(tc, test_strrchr_4);
  tcase_add_test(tc, test_strrchr_5);
  tcase_add_test(tc, test_strrchr_6);
  tcase_add_test(tc, test_strrchr_7);
  tcase_add_test(tc, test_strrchr_8);
  tcase_add_test(tc, test_strrchr_9);
  tcase_add_test(tc, test_strrchr_10);
  tcase_add_test(tc, test_strrchr_11);
  tcase_add_test(tc, test_strrchr_12);
  tcase_add_test(tc, test_strrchr_13);
  tcase_add_test(tc, test_strrchr_14);
  return s;
}
