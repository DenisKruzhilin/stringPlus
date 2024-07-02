#include <stdio.h>

#include "tests.h"

START_TEST(test_sprintf_p_1) {
  char str_out1[50];
  char str_out2[50];
  char str_in[] = "Pointer: %p";
  int chr_in = 127;
  int* ptr = &chr_in;
  int res1 = sprintf(str_out1, str_in, ptr);
  int res2 = s21_sprintf(str_out2, str_in, ptr);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_p_2) {
  char str_out1[50];
  char str_out2[50];
  char str_in[] = "Pointers: %p %p %p";
  int chr_in1 = 127;
  int chr_in2 = 127;
  int* ptr1 = &chr_in1;
  int* ptr2 = &chr_in2;
  int res1 = sprintf(str_out1, str_in, ptr1, ptr2, ptr1);
  int res2 = s21_sprintf(str_out2, str_in, ptr1, ptr2, ptr1);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_p_3) {
  char str_out1[200];
  char str_out2[200];
  char str_in[] = "Pointers: %25p %35p %40p";
  int chr_in1 = 127;
  int chr_in2 = 127;
  int* ptr1 = &chr_in1;
  int* ptr2 = &chr_in2;
  int res1 = sprintf(str_out1, str_in, ptr1, ptr2, ptr1);
  int res2 = s21_sprintf(str_out2, str_in, ptr1, ptr2, ptr1);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_p_4) {
  char str_out1[200];
  char str_out2[200];
  char str_in[] = "Pointers: %-p %-10p %p";
  int chr_in1 = 127;
  int chr_in2 = 127;
  int* ptr1 = &chr_in1;
  int* ptr2 = &chr_in2;
  int res1 = sprintf(str_out1, str_in, ptr1, ptr2, ptr1);
  int res2 = s21_sprintf(str_out2, str_in, ptr1, ptr2, ptr1);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_p_5) {
  char str_out1[200];
  char str_out2[200];
  char str_in[] = "Pointers: %-*p %-20p %p";
  int chr_in1 = 127;
  int chr_in2 = 127;
  int* ptr1 = &chr_in1;
  int* ptr2 = &chr_in2;
  int res1 = sprintf(str_out1, str_in, 30, ptr1, ptr2, ptr1);
  int res2 = s21_sprintf(str_out2, str_in, 30, ptr1, ptr2, ptr1);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite* s21_sprintf_p_suite(void) {
  Suite* s = suite_create("s21_sprintf_p");
  TCase* tc = tcase_create("s21_sprintf_p");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_sprintf_p_1);
  tcase_add_test(tc, test_sprintf_p_2);
  tcase_add_test(tc, test_sprintf_p_3);
  tcase_add_test(tc, test_sprintf_p_4);
  tcase_add_test(tc, test_sprintf_p_5);
  return s;
}
