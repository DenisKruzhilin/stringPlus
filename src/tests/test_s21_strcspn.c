#include "tests.h"

START_TEST(test_strcspn_1) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "olleh";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_2) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_3) {
  char str1[] = "";
  char str2[] = "12315433";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_4) {
  char str1[] = "HEllo1, WoRld!";
  char str2[] = "123";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_5) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "123";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_6) {
  char str1[] = "HEllo\n\r, WoRld!";
  char str2[] = "\n";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_7) {
  char str1[] = "HEllo\n\r, WoRld!";
  char str2[] = "\r";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_8) {
  char str1[] = "HEllo\n\r, WoRld!";
  char str2[] = "H";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_9) {
  char str1[] = "HEllo\n\r, WoRld!";
  char str2[] = "!";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_10) {
  char str1[] = "HEllo\n\r, WoRld!";
  char str2[] = "\0";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_11) {
  char str1[] = "HEllo\n\r, WoRld!";
  char str2[] = "W";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_12) {
  char str1[] = "HEllo\n\r, WoRld!";
  char str2[] = "Wd";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_13) {
  char str1[] = "HEllo\n\r, WoRld!";
  char str2[] = "dW";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_14) {
  char str1[] = "HEllo\n\r, WoRld!";
  char str2[] = "Wol";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_15) {
  char str1[] = "HEllo\n\r, WoRld!";
  char str2[] = "loW";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_16) {
  char str1[] = "HEllo\n\r, WoRld!";
  char str2[] = "HElo";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *s = suite_create("s21_strcspn");
  TCase *tc = tcase_create("s21_strcspn");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strcspn_1);
  tcase_add_test(tc, test_strcspn_2);
  tcase_add_test(tc, test_strcspn_3);
  tcase_add_test(tc, test_strcspn_4);
  tcase_add_test(tc, test_strcspn_5);
  tcase_add_test(tc, test_strcspn_6);
  tcase_add_test(tc, test_strcspn_7);
  tcase_add_test(tc, test_strcspn_8);
  tcase_add_test(tc, test_strcspn_9);
  tcase_add_test(tc, test_strcspn_10);
  tcase_add_test(tc, test_strcspn_11);
  tcase_add_test(tc, test_strcspn_12);
  tcase_add_test(tc, test_strcspn_13);
  tcase_add_test(tc, test_strcspn_14);
  tcase_add_test(tc, test_strcspn_15);
  tcase_add_test(tc, test_strcspn_16);
  return s;
}
