#include "tests.h"

START_TEST(test_strchr_1) {
  char str[] = "hello";
  char c = 'h';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_strchr_2) {
  char str[] = "hello";
  char c = 'e';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_strchr_3) {
  char str[] = "hello";
  char c = 'l';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_strchr_4) {
  char str[] = "hello";
  char c = 'o';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_strchr_5) {
  char str[] = "gfsaf\ngdsafsad";
  char c = '\n';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_strchr_6) {
  char str[] = "hello";
  int c = 'o';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_strchr_7) {
  char str[] = "fsdAsdafA";
  int c = 64;
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_strchr_8) {
  char str[] = "";
  int c = 64;
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_strchr_9) {
  char str[] = "\0";
  int c = '\n';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_strchr_10) {
  char str[] = "";
  int c = '\r';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_strchr_11) {
  char str[] = "\n\n\n\n\r\n\n\n\n\n";
  int c = '\r';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_strchr_12) {
  char str[] = "\n\n\n\n\r\n\n\n\n\n";
  int c = '\r';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_strchr_13) {
  char str[] = "\n\n\n\n\r\n\n\n\n\n";
  int c = '\r';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_strchr_14) {
  char str[] = "\n\n\n\n\r\nfdsa\n\n\n\n";
  int c = 'a';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

Suite *s21_strchr_suite(void) {
  Suite *s = suite_create("s21_strchr");
  TCase *tc = tcase_create("s21_strchr");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strchr_1);
  tcase_add_test(tc, test_strchr_2);
  tcase_add_test(tc, test_strchr_3);
  tcase_add_test(tc, test_strchr_4);
  tcase_add_test(tc, test_strchr_5);
  tcase_add_test(tc, test_strchr_6);
  tcase_add_test(tc, test_strchr_7);
  tcase_add_test(tc, test_strchr_8);
  tcase_add_test(tc, test_strchr_9);
  tcase_add_test(tc, test_strchr_10);
  tcase_add_test(tc, test_strchr_11);
  tcase_add_test(tc, test_strchr_12);
  tcase_add_test(tc, test_strchr_13);
  tcase_add_test(tc, test_strchr_14);
  return s;
}
