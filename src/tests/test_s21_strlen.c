#include "tests.h"

START_TEST(test_strlen_1) {
  char str[] = "hello";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_2) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_3) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_4) {
  char str[] = "\n\n\n\n\n\n\n\n\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_5) {
  char str[] = "\r\n\r\ngasfdfgsa\r\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_6) {
  char str[128] = {0};
  for (int i = 0; i < 127; i++) {
    str[i] = i + 1;
  }
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_7) {
  char str[] = "just a text\n just text";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_8) {
  char str[] = "6546546213218589fda4654";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_9) {
  char str[] = "\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_10) {
  char str[] = "\0fdssda\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_11) {
  char str[] = "reason";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strlen_12) {
  char str[] = "hel\0lo";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *s = suite_create("s21_strlen");
  TCase *tc = tcase_create("s21_strlen");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strlen_1);
  tcase_add_test(tc, test_strlen_2);
  tcase_add_test(tc, test_strlen_3);
  tcase_add_test(tc, test_strlen_4);
  tcase_add_test(tc, test_strlen_5);
  tcase_add_test(tc, test_strlen_6);
  tcase_add_test(tc, test_strlen_7);
  tcase_add_test(tc, test_strlen_8);
  tcase_add_test(tc, test_strlen_9);
  tcase_add_test(tc, test_strlen_10);
  tcase_add_test(tc, test_strlen_11);
  tcase_add_test(tc, test_strlen_12);
  return s;
}
