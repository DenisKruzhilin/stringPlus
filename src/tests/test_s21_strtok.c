#include "tests.h"

START_TEST(test_strtok_1) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld!";
  char str3[] = "o";
  ck_assert_str_eq(strtok(str1, str3), s21_strtok(str2, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
}
END_TEST

START_TEST(test_strtok_2) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld!";
  char str3[] = "l";
  ck_assert_str_eq(strtok(str1, str3), s21_strtok(str2, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_ptr_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
}
END_TEST

START_TEST(test_strtok_3) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld!";
  char str3[] = "\n";
  ck_assert_str_eq(strtok(str1, str3), s21_strtok(str2, str3));
  ck_assert_ptr_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_ptr_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
}
END_TEST

START_TEST(test_strtok_4) {
  char str1[] = "";
  char str2[] = "";
  char str3[] = "\ndsaasd";
  ck_assert_ptr_eq(strtok(str1, str3), s21_strtok(str2, str3));
  ck_assert_ptr_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_ptr_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
}
END_TEST

START_TEST(test_strtok_5) {
  char str1[] = "abrkdgn";
  char str2[] = "abrkdgn";
  char *str3 = "";
  ck_assert_str_eq(strtok(str1, str3), s21_strtok(str2, str3));
}
END_TEST

START_TEST(test_strtok_6) {
  char str1[] = "abrk\ndg\nn";
  char str2[] = "abrk\ndg\nn";
  char str3[] = "\n";
  ck_assert_str_eq(strtok(str1, str3), s21_strtok(str2, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
}
END_TEST

START_TEST(test_strtok_7) {
  char str1[] = "Just a simple string to split! I am not joking!";
  char str2[] = "Just a simple string to split! I am not joking!";
  char str3[] = " ";
  ck_assert_str_eq(strtok(str1, str3), s21_strtok(str2, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
}
END_TEST

START_TEST(test_strtok_8) {
  char str1[] = "Just a simple string to split! I am not joking!";
  char str2[] = "Just a simple string to split! I am not joking!";
  char str4[] = "Just a simple string to split! I am not joking!";
  char str5[] = "Just a simple string to split! I am not joking!";
  char str3[] = " ";
  ck_assert_str_eq(strtok(str1, str3), s21_strtok(str2, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(str4, str3), s21_strtok(str5, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
  ck_assert_str_eq(strtok(S21_NULL, str3), s21_strtok(S21_NULL, str3));
}
END_TEST

START_TEST(test_strtok_9) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "HEllo, WoRld!";
  char str3[] = "o";
  ck_assert_str_eq(strtok(str1, str3), s21_strtok(str2, str3));
  ck_assert_str_eq(strtok(str1, str3), s21_strtok(str2, str3));
}
END_TEST

Suite *s21_strtok_suite(void) {
  Suite *s = suite_create("s21_strtok");
  TCase *tc = tcase_create("s21_strtok");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strtok_1);
  tcase_add_test(tc, test_strtok_2);
  tcase_add_test(tc, test_strtok_3);
  tcase_add_test(tc, test_strtok_4);
  tcase_add_test(tc, test_strtok_5);
  tcase_add_test(tc, test_strtok_6);
  tcase_add_test(tc, test_strtok_7);
  tcase_add_test(tc, test_strtok_8);
  tcase_add_test(tc, test_strtok_9);
  return s;
}
