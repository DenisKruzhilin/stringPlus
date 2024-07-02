#include "tests.h"

START_TEST(test_memcmp_0) {
  char str1[] = "HEllo, WoRld";
  char str2[] = "HEllo, WoRld!";
  s21_size_t n = s21_strlen(str2);
  ck_assert(memcmp(str1, str2, n) < 0 && s21_memcmp(str1, str2, n) < 0);
}
END_TEST

START_TEST(test_memcmp_1) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld";
  s21_size_t n = s21_strlen(str1);
  ck_assert(memcmp(str1, str2, n) > 0 && s21_memcmp(str1, str2, n) > 0);
}
END_TEST

START_TEST(test_memcmp_2) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld";
  s21_size_t n = s21_strlen(str2);
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_3) {
  char str1[] = "\0";
  char str2[] = "";
  s21_size_t n = 1;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_4) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo WoRld!";
  s21_size_t n = 10;
  ck_assert(memcmp(str1, str2, n) > 0 && s21_memcmp(str1, str2, n) > 0);
}
END_TEST

START_TEST(test_memcmp_5) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo WoRld!";
  s21_size_t n = 5;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_6) {
  char str1[] = "gfsafgdsafsad";
  char str2[] = "gfsaf";
  s21_size_t n = s21_strlen(str2);
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_7) {
  char str1[] = "gfsafgdsafsad";
  char str2[] = "gfsaf";
  s21_size_t n = s21_strlen(str1);
  ck_assert(memcmp(str1, str2, n) > 0 && s21_memcmp(str1, str2, n) > 0);
}
END_TEST

START_TEST(test_memcmp_8) {
  char str1[] = "";
  char str2[] = "\0";
  s21_size_t n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_9) {
  char str1[25] = "fasdfasdfadsfdassdfa";
  char str2[21] = "k";
  s21_size_t n = 20;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_10) {
  char str1[5] = "";
  char str2[] = "okRd";
  s21_size_t n = 4;
  ck_assert(memcmp(str1, str2, n) < 0 && s21_memcmp(str1, str2, n) < 0);
}
END_TEST

START_TEST(test_memcmp_11) {
  char str1[] = "jnkt";
  char str2[] = "jnkt";
  s21_size_t n = s21_strlen(str1);
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_12) {
  char str1[] = "jnkt";
  char str2[] = "Jrkt";
  s21_size_t n = s21_strlen(str2);
  ck_assert(memcmp(str1, str2, n) > 0 && s21_memcmp(str1, str2, n) > 0);
}
END_TEST

START_TEST(test_memcmp_13) {
  char str1[] = "fasdf";
  char str2[] = "asdf";
  s21_size_t n = s21_strlen(str1);
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_memcmp_14) {
  char str1[] = "fdfsa";
  char str2[] = "fdsa";
  s21_size_t n = s21_strlen(str2);
  ck_assert(memcmp(str1, str2, n) < 0 && s21_memcmp(str1, str2, n) < 0);
}
END_TEST

Suite *s21_memcmp_suite(void) {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc = tcase_create("s21_memcmp");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_memcmp_0);
  tcase_add_test(tc, test_memcmp_1);
  tcase_add_test(tc, test_memcmp_2);
  tcase_add_test(tc, test_memcmp_3);
  tcase_add_test(tc, test_memcmp_4);
  tcase_add_test(tc, test_memcmp_5);
  tcase_add_test(tc, test_memcmp_6);
  tcase_add_test(tc, test_memcmp_7);
  tcase_add_test(tc, test_memcmp_8);
  tcase_add_test(tc, test_memcmp_9);
  tcase_add_test(tc, test_memcmp_10);
  tcase_add_test(tc, test_memcmp_11);
  tcase_add_test(tc, test_memcmp_12);
  tcase_add_test(tc, test_memcmp_13);
  tcase_add_test(tc, test_memcmp_14);
  return s;
}
