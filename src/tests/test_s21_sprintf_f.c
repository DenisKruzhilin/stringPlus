#include <stdio.h>

#include "tests.h"

START_TEST(test_sprintf_f_1) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "HE%f%fo, WoR%fd!";
  float chr_in = 127.;
  int res1 = sprintf(str_out1, str_in, chr_in, chr_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in, chr_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_2) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "HE%flo, WoRld!!";
  float chr_in = 0.0;
  int res1 = sprintf(str_out1, str_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_3) {
  char str_out1[300];
  char str_out2[300];
  char str_in[] = "%f%f%f%f%f%f";
  float chr_in_1 = 12.35;
  float chr_in_2 = 1.0;
  float chr_in_3 = 2.0;
  float chr_in_4 = chr_in_2 + chr_in_3;
  float chr_in_5 = 255.1639e-99;
  float chr_in_6 = -255.16;

  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5, chr_in_6);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5, chr_in_6);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_4) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1% #-f2%-+#f3%+-0f4%# +f5%- 0f";
  float chr_in_1 = 12.35;
  float chr_in_2 = 1.0;
  float chr_in_3 = 2.0;
  float chr_in_4 = chr_in_2 + chr_in_3;
  float chr_in_5 = 255.1639e-99;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_5) {
  char str_out1[1000];
  char str_out2[1000];
  char str_in[] = "1%#124.90f2%#05f3%-05f4%0143.10f";
  float chr_in_1 = 12.35;
  float chr_in_2 = 1.0;
  float chr_in_3 = 2.0;
  float chr_in_4 = chr_in_2 + chr_in_3;
  float chr_in_5 = 255.1639e-99;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_6) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%-.f2%+2.f3% 2.0f4%#.*f 5%05f";
  float chr_in_1 = 12.35;
  float chr_in_2 = 1.0;
  float chr_in_3 = 2.0;
  float chr_in_4 = chr_in_2 + chr_in_3;
  float chr_in_5 = 255.1639e-99;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     5, chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, 5, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_7) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%+2.5f2%-2.5f3%#2.5f4% 2.5f5%02.5f";
  float chr_in_1 = 12.35;
  float chr_in_2 = 1.0;
  float chr_in_3 = 2.0;
  float chr_in_4 = chr_in_2 + chr_in_3;
  float chr_in_5 = 255.1639e-99;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_8) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%0f2%08f3%-08f4%+ 8f";
  float chr_in_1 = 12.35;
  float chr_in_2 = 1.0;
  float chr_in_3 = 2.0;
  float chr_in_4 = chr_in_2 + chr_in_3;
  float chr_in_5 = 255.1639e-99;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_9) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%5f2%5f3%+ 5f4%-5f";
  float chr_in_1 = 12.35;
  float chr_in_2 = 1.0;
  float chr_in_3 = 2.0;
  float chr_in_4 = chr_in_2 + chr_in_3;
  float chr_in_5 = 255.1639e-99;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_10) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%0.8f2%0.8f3%+0.8f4%-0.8f";
  float chr_in_1 = 12.35;
  float chr_in_2 = 1.0;
  float chr_in_3 = 2.0;
  float chr_in_4 = chr_in_2 + chr_in_3;
  float chr_in_5 = 255.1639e-99;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_11) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%+f2%+f3%+f4%+f";
  float chr_in_1 = 12.35;
  float chr_in_2 = 1.0;
  float chr_in_3 = 2.0;
  float chr_in_4 = chr_in_2 + chr_in_3;
  float chr_in_5 = 255.1639e-99;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_12) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%-f2%-f3%-f4%-f";
  float chr_in_1 = 12.35;
  float chr_in_2 = 1.0;
  float chr_in_3 = 2.0;
  float chr_in_4 = chr_in_2 + chr_in_3;
  float chr_in_5 = 255.1639e-99;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_13) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%2.0f2%2.10f3%+2.6f4%-30.5f";
  float chr_in_1 = 12.35;
  float chr_in_2 = 1.0;
  float chr_in_3 = 2.0;
  float chr_in_4 = chr_in_2 + chr_in_3;
  float chr_in_5 = 255.1639e-99;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_14) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%lf2%lf3%lf4%lf";
  double chr_in_1 = 12.35;
  double chr_in_2 = 1.0;
  double chr_in_3 = 2.0;
  double chr_in_4 = chr_in_2 + chr_in_3;
  double chr_in_5 = 255.1639e-99;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_15) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%Lf2%Lf3%Lf4%Lf";
  long double chr_in_1 = 12.35;
  long double chr_in_2 = 1.0;
  long double chr_in_3 = 2.0;
  long double chr_in_4 = chr_in_2 + chr_in_3;
  long double chr_in_5 = 255.1639e-99;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_16) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%hf2%hf3%hf4%hf";
  float chr_in_1 = 12.35;
  float chr_in_2 = 1.0;
  float chr_in_3 = 2.0;
  float chr_in_4 = chr_in_2 + chr_in_3;
  float chr_in_5 = 255.1639e-99;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_f_17) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "abra%fcadabra";
  float chr_in_1 = 2.0;

  int res1 = sprintf(str_out1, str_in, chr_in_1);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_f_suite(void) {
  Suite *s = suite_create("s21_sprintf_f");
  TCase *tc = tcase_create("s21_sprintf_f");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_sprintf_f_1);
  tcase_add_test(tc, test_sprintf_f_2);
  tcase_add_test(tc, test_sprintf_f_3);
  tcase_add_test(tc, test_sprintf_f_4);
  tcase_add_test(tc, test_sprintf_f_5);
  tcase_add_test(tc, test_sprintf_f_6);
  tcase_add_test(tc, test_sprintf_f_7);
  tcase_add_test(tc, test_sprintf_f_8);
  tcase_add_test(tc, test_sprintf_f_9);
  tcase_add_test(tc, test_sprintf_f_10);
  tcase_add_test(tc, test_sprintf_f_11);
  tcase_add_test(tc, test_sprintf_f_12);
  tcase_add_test(tc, test_sprintf_f_13);
  tcase_add_test(tc, test_sprintf_f_14);
  tcase_add_test(tc, test_sprintf_f_15);
  tcase_add_test(tc, test_sprintf_f_16);
  tcase_add_test(tc, test_sprintf_f_17);
  return s;
}
