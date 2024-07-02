#include <stdio.h>

#include "tests.h"

START_TEST(test_sprintf_e_1) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "Value: %e, %e, %e";
  double chr_in1 = 1.23;
  double chr_in2 = 456.789;
  double chr_in3 = 0.0000123;
  int res1 = sprintf(str_out1, str_in, chr_in1, chr_in2, chr_in3);
  int res2 = s21_sprintf(str_out2, str_in, chr_in1, chr_in2, chr_in3);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_e_2) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "Exp: %e";
  double chr_in = 1024.2048;
  int res1 = sprintf(str_out1, str_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_e_3) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "%e %e %e %e %e";
  double chr_in1 = 1e-10;
  double chr_in2 = 1.1e10;
  double chr_in3 = -5.5e-5;
  double chr_in4 = 6.022e23;
  double chr_in5 = 9.81;
  int res1 =
      sprintf(str_out1, str_in, chr_in1, chr_in2, chr_in3, chr_in4, chr_in5);
  int res2 = s21_sprintf(str_out2, str_in, chr_in1, chr_in2, chr_in3, chr_in4,
                         chr_in5);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_e_4) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "Flags: %#e %#E %#e";
  double chr_in1 = 0.000123;
  double chr_in2 = 123000000;
  double chr_in3 = 1.0;
  int res1 = sprintf(str_out1, str_in, chr_in1, chr_in2, chr_in3);
  int res2 = s21_sprintf(str_out2, str_in, chr_in1, chr_in2, chr_in3);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_e_5) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "Width: %10e %-10e";
  double chr_in1 = 3.14159;
  double chr_in2 = 2.71828;
  int res1 = sprintf(str_out1, str_in, chr_in1, chr_in2);
  int res2 = s21_sprintf(str_out2, str_in, chr_in1, chr_in2);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_e_6) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "Precision: %.5e %.2e";
  double chr_in1 = 1234.56789;
  double chr_in2 = 9876.54321;
  int res1 = sprintf(str_out1, str_in, chr_in1, chr_in2);
  int res2 = s21_sprintf(str_out2, str_in, chr_in1, chr_in2);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_e_7) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "Zero padding: %010e";
  double chr_in = 0.123456;
  int res1 = sprintf(str_out1, str_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_e_8) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "Mixed: %5.3e %-5.3e %#5.3e";
  double chr_in1 = 1.234;
  double chr_in2 = 5.678;
  double chr_in3 = 9.012;
  int res1 = sprintf(str_out1, str_in, chr_in1, chr_in2, chr_in3);
  int res2 = s21_sprintf(str_out2, str_in, chr_in1, chr_in2, chr_in3);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_e_9) {
  char str_out1[1000];
  char str_out2[1000];
  char str_in[] = "Multiple: %115.5e %43.5E %16.112e";
  double chr_in1 = 1.23;
  double chr_in2 = 456.78;
  double chr_in3 = 9.01;
  int res1 = sprintf(str_out1, str_in, chr_in1, chr_in2, chr_in3);
  int res2 = s21_sprintf(str_out2, str_in, chr_in1, chr_in2, chr_in3);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_e_10) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "Special case: %#.0e %.0e";
  double chr_in1 = 0.0;
  double chr_in2 = 0.0;
  int res1 = sprintf(str_out1, str_in, chr_in1, chr_in2);
  int res2 = s21_sprintf(str_out2, str_in, chr_in1, chr_in2);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_e_11) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "Long: %le %lE";
  double chr_in1 = 1.23456789e10;
  double chr_in2 = 9.87654321e-10;
  int res1 = sprintf(str_out1, str_in, chr_in1, chr_in2);
  int res2 = s21_sprintf(str_out2, str_in, chr_in1, chr_in2);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_e_12) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "Short: %he %hE";
  double chr_in1 = 12.34;
  double chr_in2 = 56.78;
  int res1 = sprintf(str_out1, str_in, chr_in1, chr_in2);
  int res2 = s21_sprintf(str_out2, str_in, chr_in1, chr_in2);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_e_suite(void) {
  Suite *s = suite_create("s21_sprintf_e");
  TCase *tc = tcase_create("s21_sprintf_e");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_sprintf_e_1);
  tcase_add_test(tc, test_sprintf_e_2);
  tcase_add_test(tc, test_sprintf_e_3);
  tcase_add_test(tc, test_sprintf_e_4);
  tcase_add_test(tc, test_sprintf_e_5);
  tcase_add_test(tc, test_sprintf_e_6);
  tcase_add_test(tc, test_sprintf_e_7);
  tcase_add_test(tc, test_sprintf_e_8);
  tcase_add_test(tc, test_sprintf_e_9);
  tcase_add_test(tc, test_sprintf_e_10);
  tcase_add_test(tc, test_sprintf_e_11);
  tcase_add_test(tc, test_sprintf_e_12);
  return s;
}
