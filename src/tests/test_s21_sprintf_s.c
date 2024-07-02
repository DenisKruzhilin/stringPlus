#include <stdio.h>

#include "tests.h"

START_TEST(test_sprintf_s_1) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "HE%s%so, WoR%sd!";
  char chr_in[] = "l";
  int res1 = sprintf(str_out1, str_in, chr_in, chr_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in, chr_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_2) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "HE%slo, WoRld!!";
  char chr_in[] = "l";
  int res1 = sprintf(str_out1, str_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_3) {
  char str_out1[1000];
  char str_out2[1000];
  char str_in[] = "%s%s%s%s%s%s";
  char chr_in_1[] =
      "stringkjfdhgkjfdhgkjfdhgkfdjhgkfdjhgkjfdshgkjfdsngfdngkjfdngfd";
  char chr_in_2[] = " ";
  char chr_in_3[] = "of";
  char chr_in_4[] = " ";
  char chr_in_5[] = "unknownfdjkghdfkjhgfdkjhgkjfdhgkjfdhgkjdfhgkjdhgdf";
  char chr_in_6[] =
      " format "
      "!)"
      "xzssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"
      "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";

  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5, chr_in_6);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5, chr_in_6);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_4) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1% #-f2%-+#f3%+-0f4%# +f5%- 0f";
  char chr_in_1[] = "string";
  char chr_in_2[] = "floating";
  char chr_in_3[] = "2.0";
  char chr_in_4[] = "point";
  char chr_in_5[] = "seven";
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_5) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%#s2%#05s3%-05s4% 05s";
  char chr_in_1[] = "string";
  char chr_in_2[] = "floating";
  char chr_in_3[] = "2.0";
  char chr_in_4[] = "point";
  char chr_in_5[] = "seven";
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_6) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%-.s2%+.s3% .s4%#.s 5%05s";
  char chr_in_1[] = "string";
  char chr_in_2[] = "floating";
  char chr_in_3[] = "2.0";
  char chr_in_4[] = "point";
  char chr_in_5[] = "seven";
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_7) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%+2.5s2%-2.5s3%#2.5s4% 2.5s5%02.5s";
  char chr_in_1[] = "string";
  char chr_in_2[] = "floating";
  char chr_in_3[] = "2.0";
  char chr_in_4[] = "point";
  char chr_in_5[] = "seven";
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_8) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%0s2%08s3%-08s4%+ 8s";
  char chr_in_1[] = "string";
  char chr_in_2[] = "floating";
  char chr_in_3[] = "2.0";
  char chr_in_4[] = "point";
  char chr_in_5[] = "seven";
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_9) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%5s2%5s3%+ 5s4%-5s";
  char chr_in_1[] = "string";
  char chr_in_2[] = "floating";
  char chr_in_3[] = "2.0";
  char chr_in_4[] = "point";
  char chr_in_5[] = "seven";
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_10) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%0.8s2%0.8s3%+0.8s4%-0.8s";
  char chr_in_1[] = "string";
  char chr_in_2[] = "floating";
  char chr_in_3[] = "2.0";
  char chr_in_4[] = "point";
  char chr_in_5[] = "seven";
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_11) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%+s2%+s3%+s4%+s";
  char chr_in_1[] = "string";
  char chr_in_2[] = "floating";
  char chr_in_3[] = "2.0";
  char chr_in_4[] = "point";
  char chr_in_5[] = "seven";
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_12) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%-s2%-s3%-s4%-s";
  char chr_in_1[] = "string";
  char chr_in_2[] = "floating";
  char chr_in_3[] = "2.0";
  char chr_in_4[] = "point";
  char chr_in_5[] = "seven";
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_13) {
  char str_out1[400];
  char str_out2[400];
  char str_in[] = "1%200.0s2%2.10s3%+2.6s4%-30.5s";
  char chr_in_1[] = "string";
  char chr_in_2[] = "floating";
  char chr_in_3[] = "2.0";
  char chr_in_4[] = "point";
  char chr_in_5[] = "seven";
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_14) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%ls2%ls3%ls4%ls";
  wchar_t* chr_in_1 = L"string";
  wchar_t* chr_in_2 = L"floating";
  wchar_t* chr_in_3 = L"2.0";
  wchar_t* chr_in_4 = L"point";
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4);
  int res2 =
      s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_15) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%Ls2%Ls3%Ls4%Ls5%Ls";
  wchar_t* chr_in_1 = L"string";
  wchar_t* chr_in_2 = L"floating";
  wchar_t* chr_in_3 = L"2.0";
  wchar_t* chr_in_4 = L"point";
  wchar_t* chr_in_5 = L"seven";
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_16) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%hs2%hs3%hs4%hs";
  char chr_in_1[] = "string";
  char chr_in_2[] = "floating";
  char chr_in_3[] = "2.0";
  char chr_in_4[] = "point";
  char chr_in_5[] = "seven";
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_s_17) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "abra%scadabra";
  char chr_in_1[] = "";

  int res1 = sprintf(str_out1, str_in, chr_in_1);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite* s21_sprintf_s_suite(void) {
  Suite* s = suite_create("s21_sprintf_s");
  TCase* tc = tcase_create("s21_sprintf_s");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_sprintf_s_1);
  tcase_add_test(tc, test_sprintf_s_2);
  tcase_add_test(tc, test_sprintf_s_3);
  tcase_add_test(tc, test_sprintf_s_4);
  tcase_add_test(tc, test_sprintf_s_5);
  tcase_add_test(tc, test_sprintf_s_6);
  tcase_add_test(tc, test_sprintf_s_7);
  tcase_add_test(tc, test_sprintf_s_8);
  tcase_add_test(tc, test_sprintf_s_9);
  tcase_add_test(tc, test_sprintf_s_10);
  tcase_add_test(tc, test_sprintf_s_11);
  tcase_add_test(tc, test_sprintf_s_12);
  tcase_add_test(tc, test_sprintf_s_13);
  tcase_add_test(tc, test_sprintf_s_14);
  tcase_add_test(tc, test_sprintf_s_15);
  tcase_add_test(tc, test_sprintf_s_16);
  tcase_add_test(tc, test_sprintf_s_17);
  return s;
}
