#include "tests.h"

START_TEST(test_memset_1) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld!";
  int chr = '0';
  s21_size_t n = 1;
  ck_assert_str_eq(memset(str1, chr, n), s21_memset(str2, chr, n));
}
END_TEST

START_TEST(test_memset_2) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld!";
  int chr = '0';
  s21_size_t n = 5;
  ck_assert_str_eq(memset(str1, chr, n), s21_memset(str2, chr, n));
}
END_TEST

START_TEST(test_memset_3) {
  char str1[5] = "";
  char str2[5] = "";
  int chr = '0';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(str1, chr, n), s21_memset(str2, chr, n));
}
END_TEST

START_TEST(test_memset_4) {
  char str1[5] = "";
  char str2[5] = "";
  int chr = '0';
  s21_size_t n = 1;
  ck_assert_str_eq(memset(str1, chr, n), s21_memset(str2, chr, n));
}
END_TEST

START_TEST(test_memset_5) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld!";
  int chr = '\0';
  s21_size_t n = 1;
  ck_assert_str_eq(memset(str1, chr, n), s21_memset(str2, chr, n));
}
END_TEST

START_TEST(test_memset_6) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld!";
  int chr = '\0';
  s21_size_t n = 5;
  ck_assert_str_eq(memset(str1, chr, n), s21_memset(str2, chr, n));
}
END_TEST

START_TEST(test_memset_7) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld!";
  int chr = '\0';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(str1, chr, n), s21_memset(str2, chr, n));
}
END_TEST

START_TEST(test_memset_8) {
  char str1[] = "12385462123";
  char str2[] = "12385462123";
  int chr = '\n';
  s21_size_t n = 1;
  ck_assert_str_eq(memset(str1, chr, n), s21_memset(str2, chr, n));
}
END_TEST

START_TEST(test_memset_9) {
  char str1[] = "fasdfasd\nfadsfdassdfa\0";
  char str2[] = "fasdfasd\nfadsfdassdfa\0";
  int chr = '\n';
  s21_size_t n = s21_strlen(str1) + 1;
  ck_assert_str_eq(memset(str1, chr, n), s21_memset(str2, chr, n));
}
END_TEST

START_TEST(test_memset_10) {
  char str1[] = "okRd";
  char str2[] = "okRd";
  int chr = 1;
  s21_size_t n = 0;
  ck_assert_str_eq(memset(str1, chr, n), s21_memset(str2, chr, n));
}
END_TEST

START_TEST(test_memset_11) {
  char str1[127] = "ok\nRd";
  char str2[127] = "ok\nRd";
  int chr = 122;
  s21_size_t n = 122;
  ck_assert_str_eq(memset(str1, chr, n), s21_memset(str2, chr, n));
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *s = suite_create("s21_memset");
  TCase *tc = tcase_create("s21_memset");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_memset_1);
  tcase_add_test(tc, test_memset_2);
  tcase_add_test(tc, test_memset_3);
  tcase_add_test(tc, test_memset_4);
  tcase_add_test(tc, test_memset_5);
  tcase_add_test(tc, test_memset_6);
  tcase_add_test(tc, test_memset_7);
  tcase_add_test(tc, test_memset_8);
  tcase_add_test(tc, test_memset_9);
  tcase_add_test(tc, test_memset_10);
  tcase_add_test(tc, test_memset_11);
  return s;
}
