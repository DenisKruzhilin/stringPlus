#include <stdio.h>

#include "tests.h"

START_TEST(test_sprintf_u_1) {
  char str_out1[50];
  char str_out2[50];
  char str_in[] = "HE%u%uo, WoR%ud!";
  int chr_in = 127;
  int res1 = sprintf(str_out1, str_in, chr_in, chr_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in, chr_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_u_2) {
  char str_out1[50];
  char str_out2[50];
  char str_in[] = "HE%ulo, WoRld!!";
  int chr_in = 0;
  int res1 = sprintf(str_out1, str_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_u_3) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "%u%u%u%u%u%u%u%u%u%u%u%u%u";
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

START_TEST(test_sprintf_u_4) {
  char str_out1[1000];
  char str_out2[1000];
  char str_in[] = "1% #-230.34u2%-+#u3%+-0u4%# +u5%- 023.78u";
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

START_TEST(test_sprintf_u_5) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%#u2%#05u3%-05u4% 05u";
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

START_TEST(test_sprintf_u_6) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%-.u2%+.u3% .u4%#.u 5%05u";
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

START_TEST(test_sprintf_u_7) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%+2.5u2%-2.5u3%#2.5u4% 2.5u5%02.5u";
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

START_TEST(test_sprintf_u_8) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%0u2%08u3%-08u4%+ 8u";
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

START_TEST(test_sprintf_u_9) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%5u2%5u3%+ 5u4%-5u";
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

START_TEST(test_sprintf_u_10) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%0.8u2%0.8u3%+0.8u4%-0.8u";
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

START_TEST(test_sprintf_u_11) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%+u2%+u3%+u4%+u";
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

START_TEST(test_sprintf_u_12) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%-u2%-u3%-u4%-u5%-05u";
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

START_TEST(test_sprintf_u_13) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%2u2%2.u3%+2.*u4%-2.0u5";
  int chr_in_1 = 31;
  int chr_in_2 = 525;
  int chr_in_3 = 68;
  int chr_in_4 = 122;
  int res1 =
      sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, 5, chr_in_4);
  int res2 =
      s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3, 5, chr_in_4);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_u_14) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%0lu2% lu3%-.*u4%2.0lu5%0.5lu";
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

START_TEST(test_sprintf_u_15) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%Lu2%Lu3%Lu4%Lu5%Lu";
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

START_TEST(test_sprintf_u_16) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%hu2%hu3%hu4%hu";
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

START_TEST(test_sprintf_u_17) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "abra%ucauabra";
  int chr_in_1 = 0;

  int res1 = sprintf(str_out1, str_in, chr_in_1);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_u_suite(void) {
  Suite *s = suite_create("s21_sprintf_u");
  TCase *tc = tcase_create("s21_sprintf_u");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_sprintf_u_1);
  tcase_add_test(tc, test_sprintf_u_2);
  tcase_add_test(tc, test_sprintf_u_3);
  tcase_add_test(tc, test_sprintf_u_4);
  tcase_add_test(tc, test_sprintf_u_5);
  tcase_add_test(tc, test_sprintf_u_6);
  tcase_add_test(tc, test_sprintf_u_7);
  tcase_add_test(tc, test_sprintf_u_8);
  tcase_add_test(tc, test_sprintf_u_9);
  tcase_add_test(tc, test_sprintf_u_10);
  tcase_add_test(tc, test_sprintf_u_11);
  tcase_add_test(tc, test_sprintf_u_12);
  tcase_add_test(tc, test_sprintf_u_13);
  tcase_add_test(tc, test_sprintf_u_14);
  tcase_add_test(tc, test_sprintf_u_15);
  tcase_add_test(tc, test_sprintf_u_16);
  tcase_add_test(tc, test_sprintf_u_17);
  return s;
}
