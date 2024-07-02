#include <stdio.h>

#include "tests.h"

START_TEST(test_sprintf_c_1) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "HE%c%co, WoR%cd!";
  int chr_in = 127;
  int res1 = sprintf(str_out1, str_in, chr_in, chr_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in, chr_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_c_2) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "HE%clo, WoRld!!";
  int chr_in = 0;
  int res1 = sprintf(str_out1, str_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_c_3) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "%c%c%c%c%c%c%c%c%c%c%c%c%c";
  int chr_in_1 = 'H';
  int chr_in_2 = 'e';
  int chr_in_3 = 'l';
  int chr_in_4 = 'l';
  int chr_in_5 = 'o';
  int chr_in_6 = ',';
  int chr_in_7 = ' ';
  int chr_in_8 = 'w';
  int chr_in_9 = 'o';
  int chr_in_10 = 'r';
  int chr_in_11 = 'l';
  int chr_in_12 = 'd';
  int chr_in_13 = '!';
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5, chr_in_6, chr_in_7, chr_in_8, chr_in_9,
                     chr_in_10, chr_in_11, chr_in_12, chr_in_13);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5, chr_in_6, chr_in_7, chr_in_8,
                         chr_in_9, chr_in_10, chr_in_11, chr_in_12, chr_in_13);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_c_4) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1% #-c2%-+#c3%+-0c4%# +c5%- 0c";
  int chr_in_1 = 31;
  int chr_in_2 = 525;
  int chr_in_3 = 68;
  int chr_in_4 = 122;
  int chr_in_5 = 77;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_c_5) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%#c2%#-5c3%-5c4% +5c";
  int chr_in_1 = 38;
  int chr_in_2 = 67;
  int chr_in_3 = 68;
  int chr_in_4 = 122;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4);
  int res2 =
      s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_c_6) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%-.c2%+.c3% .c4%#.c 5%5c";
  int chr_in_1 = 38;
  int chr_in_2 = 67;
  int chr_in_3 = 68;
  int chr_in_4 = 122;
  int chr_in_5 = 77;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_c_7) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%+2.5c2%-2.5c3%#2.5c4% 2.5c5%02.5c";
  int chr_in_1 = 31;
  int chr_in_2 = 525;
  int chr_in_3 = 68;
  int chr_in_4 = 122;
  int chr_in_5 = 77;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_c_8) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%+2.5lc2%-2.5lc3%#2.5lc4% 2.5lc5%02.5lc";
  wchar_t chr_in_1 = L'a';
  wchar_t chr_in_2 = L'b';
  wchar_t chr_in_3 = L'c';
  wchar_t chr_in_4 = L'd';
  wchar_t chr_in_5 = L'e';
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_c_9) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%+2.5Lc2%-2.5Lc3%#2.5Lc4% 2.5Lc5%02.5Lc";
  wchar_t chr_in_1 = L'a';
  wchar_t chr_in_2 = L'b';
  wchar_t chr_in_3 = L'c';
  wchar_t chr_in_4 = L'd';
  wchar_t chr_in_5 = L'e';
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_c_10) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%+2.5hc2%-2.5hc3%#2.5hc4% 2.5hc5%02.5hc";
  int chr_in_1 = 31;
  int chr_in_2 = 525;
  int chr_in_3 = 68;
  int chr_in_4 = 122;
  int chr_in_5 = 77;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_c_11) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "abra%ccadabra";
  int chr_in_1 = '\0';
  int res1 = sprintf(str_out1, str_in, chr_in_1);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_c_suite(void) {
  Suite *s = suite_create("s21_sprintf_c");
  TCase *tc = tcase_create("s21_sprintf_c");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_sprintf_c_1);
  tcase_add_test(tc, test_sprintf_c_2);
  tcase_add_test(tc, test_sprintf_c_3);
  tcase_add_test(tc, test_sprintf_c_4);
  tcase_add_test(tc, test_sprintf_c_5);
  tcase_add_test(tc, test_sprintf_c_6);
  tcase_add_test(tc, test_sprintf_c_7);
  tcase_add_test(tc, test_sprintf_c_8);
  tcase_add_test(tc, test_sprintf_c_9);
  tcase_add_test(tc, test_sprintf_c_10);
  tcase_add_test(tc, test_sprintf_c_11);
  return s;
}
