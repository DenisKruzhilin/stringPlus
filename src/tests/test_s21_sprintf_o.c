#include <stdio.h>

#include "tests.h"

START_TEST(test_sprintf_o_1) {
  char str_out1[50];
  char str_out2[50];
  char str_in[] = "HE%o%oo, WoR%od!";
  int chr_in = 127;
  int res1 = sprintf(str_out1, str_in, chr_in, chr_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in, chr_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_o_2) {
  char str_out1[50];
  char str_out2[50];
  char str_in[] = "HE%olo, WoRld!!";
  int chr_in = 0;
  int res1 = sprintf(str_out1, str_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_o_3) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "%o%o%o%o%o";
  int chr_in_1 = 'H';
  int chr_in_2 = 'e';
  int chr_in_3 = 'l';
  int chr_in_4 = 'l';
  int chr_in_5 = 'o';
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4,
                     chr_in_5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3,
                         chr_in_4, chr_in_5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_o_4) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1% #-o2%-+#o3%+-0o4%# +o5%- 0o";
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

START_TEST(test_sprintf_o_5) {
  char str_out1[1000];
  char str_out2[1000];
  char str_in[] = "1%-150.43o2%+.o3% .o4%#.o 5%056.128o";
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

START_TEST(test_sprintf_o_6) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%+2.5o2%-2.5o3%#2.5o4% 2.5o5%02.5o";
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

START_TEST(test_sprintf_o_7) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%0.8o2%0.8o3%+0.8o4%-0.8o";
  int chr_in_1 = 31;
  int chr_in_2 = 525;
  int chr_in_3 = 68;
  int chr_in_4 = 122;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4);
  int res2 =
      s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_o_8) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%-o2%-o3%-o4%-o5%-05o";
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

START_TEST(test_sprintf_o_9) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%2o2%2.o3%+2.*o4%-2.0o5";
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

START_TEST(test_sprintf_o_10) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%Lo2%Lo3%Lo4%Lo5%Lo";
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

START_TEST(test_sprintf_o_11) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%ho2%ho3%ho4%ho";
  int chr_in_1 = 31;
  int chr_in_2 = 525;
  int chr_in_3 = 68;
  int chr_in_4 = 122;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4);
  int res2 =
      s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_o_12) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "abra%cadabra";
  int chr_in_1 = 0;

  int res1 = sprintf(str_out1, str_in, chr_in_1);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_o_suite(void) {
  Suite *s = suite_create("s21_sprintf_o");
  TCase *tc = tcase_create("s21_sprintf_o");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_sprintf_o_1);
  tcase_add_test(tc, test_sprintf_o_2);
  tcase_add_test(tc, test_sprintf_o_3);
  tcase_add_test(tc, test_sprintf_o_4);
  tcase_add_test(tc, test_sprintf_o_5);
  tcase_add_test(tc, test_sprintf_o_6);
  tcase_add_test(tc, test_sprintf_o_7);
  tcase_add_test(tc, test_sprintf_o_8);
  tcase_add_test(tc, test_sprintf_o_9);
  tcase_add_test(tc, test_sprintf_o_10);
  tcase_add_test(tc, test_sprintf_o_11);
  tcase_add_test(tc, test_sprintf_o_12);
  return s;
}
