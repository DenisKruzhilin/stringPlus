#include <stdio.h>

#include "tests.h"

START_TEST(test_sprintf_d_1) {
  char str_out1[50];
  char str_out2[50];
  char str_in[] = "HE%d%do, WoR%dd!";
  int chr_in = 127;
  int res1 = sprintf(str_out1, str_in, chr_in, chr_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in, chr_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_d_2) {
  char str_out1[50];
  char str_out2[50];
  char str_in[] = "HE%dlo, WoRld!!";
  int chr_in = 0;
  int res1 = sprintf(str_out1, str_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_d_3) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "%d%d%d%d%d%d%d%d%d%d%d%d%d";
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

START_TEST(test_sprintf_d_4) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1% #-d2%-+#d3%+-0d4%# +d5%- 0d";
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

START_TEST(test_sprintf_d_5) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%#d2%#05d3%-05d4% 05d";
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

START_TEST(test_sprintf_d_6) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%-.d2%+.d3% .d4%#.d 5%05d";
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

START_TEST(test_sprintf_d_7) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%+2.5d2%-2.5d3%#2.5d4% 2.5d5%02.5d";
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

START_TEST(test_sprintf_d_8) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%0d2%08d3%-08d4%+ 8d";
  int chr_in_1 = 0;
  int chr_in_2 = 0;
  int chr_in_3 = 0;
  int chr_in_4 = 0;
  int chr_in_5 = 0;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_d_9) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%5d2%5d3%+ 5d4%-5d";
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

START_TEST(test_sprintf_d_10) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%0.8d2%0.8d3%+0.8d4%-0.8d";
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

START_TEST(test_sprintf_d_11) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%+d2%+d3%+d4%+d";
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

START_TEST(test_sprintf_d_12) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%-d2%-d3%-d4%-d5%-05d";
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

START_TEST(test_sprintf_d_13) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%2d2%2.d3%+2.*d4%-2.0d5";
  int chr_in_1 = 31;
  int chr_in_2 = 525;
  int chr_in_3 = 68;
  int chr_in_4 = 122;
  int res1 =
      sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, 4, chr_in_4);
  int res2 =
      s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3, 4, chr_in_4);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_d_14) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%0ld2% ld3%-.*d4%2.0ld5%0.5ld";
  long int chr_in_1 = 0x80000000;
  long int chr_in_2 = 0xFFFFFFFF;
  long int chr_in_3 = 0x0;
  long int chr_in_4 = 0x7FFFFFFF;
  long int chr_in_5 = 0x88;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, 5,
                     chr_in_4, chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3, 5,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_d_15) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%Ld2%Ld3%Ld4%Ld5%Ld";
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

START_TEST(test_sprintf_d_16) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%hd2%hd3%hd4%hd";
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

START_TEST(test_sprintf_d_17) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "abra%dcadabra";
  int chr_in_1 = 0;

  int res1 = sprintf(str_out1, str_in, chr_in_1);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_d_suite(void) {
  Suite *s = suite_create("s21_sprintf_d");
  TCase *tc = tcase_create("s21_sprintf_d");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_sprintf_d_1);
  tcase_add_test(tc, test_sprintf_d_2);
  tcase_add_test(tc, test_sprintf_d_3);
  tcase_add_test(tc, test_sprintf_d_4);
  tcase_add_test(tc, test_sprintf_d_5);
  tcase_add_test(tc, test_sprintf_d_6);
  tcase_add_test(tc, test_sprintf_d_7);
  tcase_add_test(tc, test_sprintf_d_8);
  tcase_add_test(tc, test_sprintf_d_9);
  tcase_add_test(tc, test_sprintf_d_10);
  tcase_add_test(tc, test_sprintf_d_11);
  tcase_add_test(tc, test_sprintf_d_12);
  tcase_add_test(tc, test_sprintf_d_13);
  tcase_add_test(tc, test_sprintf_d_14);
  tcase_add_test(tc, test_sprintf_d_15);
  tcase_add_test(tc, test_sprintf_d_16);
  tcase_add_test(tc, test_sprintf_d_17);
  return s;
}
