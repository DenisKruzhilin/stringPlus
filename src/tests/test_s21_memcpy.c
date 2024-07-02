#include "tests.h"

START_TEST(test_memcpy_1) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "LEjlo, WoRld?";
  char str3[] = "LEjlo, WoRld?";
  s21_size_t n = s21_strlen(str1);
  ck_assert_str_eq(memcpy(str2, str1, n), s21_memcpy(str3, str1, n));
}
END_TEST

START_TEST(test_memcpy_2) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "LEjlo, WoRld?";
  char str3[] = "LEjlo, WoRld?";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(str2, str1, n), s21_memcpy(str3, str1, n));
}
END_TEST

START_TEST(test_memcpy_3) {
  char str1[] = "HEllo, WoRld!";
  char str2[11] = "";
  char str3[11] = "";
  s21_size_t n = 10;
  ck_assert_str_eq(memcpy(str2, str1, n), s21_memcpy(str3, str1, n));
}
END_TEST

START_TEST(test_memcpy_4) {
  char str1[10] = "";
  char str2[] = "HEllo, WoRld!";
  char str3[] = "HEllo, WoRld!";
  s21_size_t n = 5;
  ck_assert_str_eq(memcpy(str2, str1, n), s21_memcpy(str3, str1, n));
}
END_TEST

START_TEST(test_memcpy_5) {
  char str1[] = "\n\n\n\n\r\n\n\n\n\n";
  char str2[] = "FFFFF";
  char str3[] = "FFFFF";
  s21_size_t n = 5;
  ck_assert_str_eq(memcpy(str2, str1, n), s21_memcpy(str3, str1, n));
}
END_TEST

START_TEST(test_memcpy_6) {
  char str1[] = "\n\n\n\n\r\n\n\n\n\n";
  char str2[20] = "FFFFF";
  char str3[20] = "FFFFF";
  s21_size_t n = 6;
  ck_assert_str_eq(memcpy(str2, str1, n), s21_memcpy(str3, str1, n));
}
END_TEST

START_TEST(test_memcpy_7) {
  char str1[] = "\n\n\n\n\r\n\n\n\n\n";
  char str2[20] = "FFFFF";
  char str3[20] = "FFFFF";
  s21_size_t n = s21_strlen(str1);
  ck_assert_str_eq(memcpy(str2, str1, n), s21_memcpy(str3, str1, n));
}
END_TEST

START_TEST(test_memcpy_8) {
  char str1[] = "\n\n\n\n\r\n\n\n\n\n";
  char str2[] = "FFFFF";
  char str3[] = "FFFFF";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(str2, str1, n), s21_memcpy(str3, str1, n));
}
END_TEST

START_TEST(test_memcpy_9) {
  char str1[] = "";
  char str2[] = "";
  char str3[] = "";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(str2, str1, n), s21_memcpy(str3, str1, n));
}
END_TEST

START_TEST(test_memcpy_10) {
  char str1[] = "";
  char str2[] = "";
  char str3[] = "";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(str2, str1, n), s21_memcpy(str3, str1, n));
}
END_TEST

START_TEST(test_memcpy_11) {
  char str1[11] = "FFFFF";
  char str2[11] = "";
  char str3[11] = "";
  s21_size_t n = 10;
  ck_assert_str_eq(memcpy(str2, str1, n), s21_memcpy(str3, str1, n));
}
END_TEST

START_TEST(test_memcpy_12) {
  char str1[10] = "";
  char str2[] = "FFFFFF";
  char str3[] = "FFFFFF";
  s21_size_t n = 5;
  ck_assert_str_eq(memcpy(str2, str1, n), s21_memcpy(str3, str1, n));
}
END_TEST

START_TEST(test_memcpy_13) {
  char str1[] = "123456";
  char str2[] = "FFFFFF";
  char str3[] = "FFFFFF";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(str2, str1, n), s21_memcpy(str3, str1, n));
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc = tcase_create("s21_memcpy");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_memcpy_1);
  tcase_add_test(tc, test_memcpy_2);
  tcase_add_test(tc, test_memcpy_3);
  tcase_add_test(tc, test_memcpy_4);
  tcase_add_test(tc, test_memcpy_5);
  tcase_add_test(tc, test_memcpy_6);
  tcase_add_test(tc, test_memcpy_7);
  tcase_add_test(tc, test_memcpy_8);
  tcase_add_test(tc, test_memcpy_9);
  tcase_add_test(tc, test_memcpy_10);
  tcase_add_test(tc, test_memcpy_11);
  tcase_add_test(tc, test_memcpy_12);
  tcase_add_test(tc, test_memcpy_13);
  return s;
}
