#include "tests.h"

START_TEST(test_strpbrk_1) {
  char str1[] = "hello";
  char str2[] = "hello";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_2) {
  char str1[] = "HEllo, WoRld!";
  char str2[] = "okRd";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_3) {
  char str1[] = "\0";
  char str2[] = "";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_4) {
  char str1[] = "hello";
  char str2[] = "okRd";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_5) {
  char str1[] = "gfsaf\ngdsafsad";
  char str2[] = "okRd";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_6) {
  char str1[] = "gfsaf\ngdsafsad";
  char str2[] = "okR";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_7) {
  char str1[] = "fsdAsdafA";
  char str2[] = "okRd";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_8) {
  char str1[] = "";
  char str2[] = "\0";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_9) {
  char str1[] = "fasdfasd\nfadsfdassdfa\0";
  char str2[] = "\n";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_10) {
  char str1[] = "";
  char str2[] = "okRd";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_11) {
  char str1[] = "\n\n\n\n\r\n\n\n\n\n";
  char str2[] = "\rnkt";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_12) {
  char str1[] = "\n\n\n\n\r\n\n\n\n\n";
  char str2[] = "\nrkt";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_13) {
  char str1[] = "\n\n\n\nfdsa\r\n\n\n\n\n";
  char str2[] = "asdf";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_14) {
  char str1[] = "\n\n\n\n\r\nfdsa\n\n\n\n";
  char str2[] = "fdsa";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc = tcase_create("s21_strpbrk");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_strpbrk_1);
  tcase_add_test(tc, test_strpbrk_2);
  tcase_add_test(tc, test_strpbrk_3);
  tcase_add_test(tc, test_strpbrk_4);
  tcase_add_test(tc, test_strpbrk_5);
  tcase_add_test(tc, test_strpbrk_6);
  tcase_add_test(tc, test_strpbrk_7);
  tcase_add_test(tc, test_strpbrk_8);
  tcase_add_test(tc, test_strpbrk_9);
  tcase_add_test(tc, test_strpbrk_10);
  tcase_add_test(tc, test_strpbrk_11);
  tcase_add_test(tc, test_strpbrk_12);
  tcase_add_test(tc, test_strpbrk_13);
  tcase_add_test(tc, test_strpbrk_14);
  return s;
}
