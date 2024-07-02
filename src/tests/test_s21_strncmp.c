#include "tests.h"

START_TEST(test_strncmp_1) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo";
  s21_size_t n = 5;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_2) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo";
  s21_size_t n = 6;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_3) {
  char str1[] = "HEllo, WoRld!";
  char str2[10] = "";
  s21_size_t n = 6;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_4) {
  char str1[10] = "";
  char str2[] = "HEllo";
  s21_size_t n = 5;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_5) {
  char str1[10] = "";
  char str2[] = "HEllo";
  s21_size_t n = 6;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_6) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld!";
  s21_size_t n = s21_strlen(str1);
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_7) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, woRld!";
  s21_size_t n = s21_strlen(str1);
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_8) {
  char str1[] = "1234567890987654321";
  char str2[] = "89098";
  s21_size_t n = s21_strlen(str1);
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_9) {
  char str1[] = "1234567890987654321";
  char str2[] = "89098";
  s21_size_t n = 0;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_10) {
  char str1[] = "89bghjkll";
  char str2[] = "89fdsfdsfds";
  s21_size_t n = 2;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_11) {
  char str1[] = "89fghjkll";
  char str2[] = "89fdsfdsfds";
  s21_size_t n = 3;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_12) {
  char str1[] = "89bghjkll";
  char str2[] = "89fdsfdsfds";
  s21_size_t n = 3;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_13) {
  char str1[] = "123456";
  char str2[] = "12345\n";
  s21_size_t n = 5;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_14) {
  char str1[] = "123456FFFFFF";
  char str2[] = "FFFFF";
  s21_size_t n = 5;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_strncmp_15) {
  char str1[] = "123456FFFFF";
  char str2[] = "FFFFF";
  s21_size_t n = 6;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

Suite *s21_strncmp_suite(void) {
  Suite *s = suite_create("s21_strncmp");
  TCase *tc = tcase_create("s21_strncmp");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strncmp_1);
  tcase_add_test(tc, test_strncmp_2);
  tcase_add_test(tc, test_strncmp_3);
  tcase_add_test(tc, test_strncmp_4);
  tcase_add_test(tc, test_strncmp_5);
  tcase_add_test(tc, test_strncmp_6);
  tcase_add_test(tc, test_strncmp_7);
  tcase_add_test(tc, test_strncmp_8);
  tcase_add_test(tc, test_strncmp_9);
  tcase_add_test(tc, test_strncmp_10);
  tcase_add_test(tc, test_strncmp_11);
  tcase_add_test(tc, test_strncmp_12);
  tcase_add_test(tc, test_strncmp_13);
  tcase_add_test(tc, test_strncmp_14);
  tcase_add_test(tc, test_strncmp_15);
  return s;
}
