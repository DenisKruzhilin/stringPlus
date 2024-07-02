#include "tests.h"

START_TEST(test_memchr_1) {
  char str[] = "hello";
  char c = 'h';
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_2) {
  char str[] = "hello";
  char c = 'e';
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_3) {
  char str[] = "hello";
  char c = 'l';
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_4) {
  char str[] = "hello";
  char c = 'o';
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_5) {
  char str[] = "gfsaf\ngdsafsad";
  char c = '\n';
  s21_size_t n = 10;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_6) {
  char str[] = "hello";
  int c = 'o';
  s21_size_t n = 4;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_7) {
  char str[] = "fsdAsdafA";
  int c = 64;
  s21_size_t n = 0;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_8) {
  char str[] = "";
  int c = 64;
  s21_size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_9) {
  char str[21] = "\0";
  int c = '\n';
  s21_size_t n = 20;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_10) {
  char str[11] = "";
  int c = '\r';
  s21_size_t n = 10;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_11) {
  char str[] = "\n\n\n\n\r\n\n\n\n\n";
  int c = '\r';
  s21_size_t n = 2;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_12) {
  char str[] = "\n\n\n\n\r\n\n\n\n\n";
  int c = '\r';
  s21_size_t n = 4;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_13) {
  char str[] = "\n\n\n\n\r\n\n\n\n\n";
  int c = '\n';
  s21_size_t n = 5;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(test_memchr_14) {
  char str[60] = "\n\n\n\n\r\nfdsa\n\n\n\n";
  int c = 'a';
  s21_size_t n = 55;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *s = suite_create("s21_memchr");
  TCase *tc = tcase_create("s21_memchr");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_memchr_1);
  tcase_add_test(tc, test_memchr_2);
  tcase_add_test(tc, test_memchr_3);
  tcase_add_test(tc, test_memchr_4);
  tcase_add_test(tc, test_memchr_5);
  tcase_add_test(tc, test_memchr_6);
  tcase_add_test(tc, test_memchr_7);
  tcase_add_test(tc, test_memchr_8);
  tcase_add_test(tc, test_memchr_9);
  tcase_add_test(tc, test_memchr_10);
  tcase_add_test(tc, test_memchr_11);
  tcase_add_test(tc, test_memchr_12);
  tcase_add_test(tc, test_memchr_13);
  tcase_add_test(tc, test_memchr_14);
  return s;
}
