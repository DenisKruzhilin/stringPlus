#include <stdio.h>

#include "tests.h"

START_TEST(test_sprintf_x_1) {
  char str_out1[50];
  char str_out2[50];
  char str_in[] = "HE%x%xo, WoR%xd!";
  int chr_in = 127;
  int res1 = sprintf(str_out1, str_in, chr_in, chr_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in, chr_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_x_2) {
  char str_out1[50];
  char str_out2[50];
  char str_in[] = "HE%xlo, WoRld!!";
  int chr_in = 0;
  int res1 = sprintf(str_out1, str_in, chr_in);
  int res2 = s21_sprintf(str_out2, str_in, chr_in);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_x_3) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "%x %x %x %x %x";
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

START_TEST(test_sprintf_x_4) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1% #-x2%-+#x3%+-0X4%# +X5%- 0x";
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

START_TEST(test_sprintf_x_5) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%#x2%#05X3%-05x4% 05x";
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

START_TEST(test_sprintf_x_6) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%-.x2%+.x3% .X4%#.x 5%05x";
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

START_TEST(test_sprintf_x_7) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%0x2%08X3%-08x4%+ 8X";
  int chr_in_1 = 0;
  int chr_in_2 = 0;
  int chr_in_3 = 0;
  int chr_in_4 = 0;
  int res1 = sprintf(str_out1, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4);
  int res2 =
      s21_sprintf(str_out2, str_in, chr_in_1, chr_in_2, chr_in_3, chr_in_4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sprintf_x_8) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%0.8x2%0.8x3%+0.8x4%-0.8x";
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

START_TEST(test_sprintf_x_9) {
  char str_out1[1000];
  char str_out2[1000];
  char str_in[] = "1%-200.7x2%-X3%-34.234x4%-x5%-05X";
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

START_TEST(test_sprintf_x_10) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%Lx2%Lx3%LX4%Lx5%Lx";
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

START_TEST(test_sprintf_x_11) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "1%hx2%hX3%hX4%hx";
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

START_TEST(test_sprintf_x_12) {
  char str_out1[100];
  char str_out2[100];
  char str_in[] = "abra%xcadabra";
  int chr_in_1 = 0;

  int res1 = sprintf(str_out1, str_in, chr_in_1);
  int res2 = s21_sprintf(str_out2, str_in, chr_in_1);
  ck_assert_str_eq(str_out1, str_out2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_x_suite(void) {
  Suite *s = suite_create("s21_sprintf_x");
  TCase *tc = tcase_create("s21_sprintf_x");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_sprintf_x_1);
  tcase_add_test(tc, test_sprintf_x_2);
  tcase_add_test(tc, test_sprintf_x_3);
  tcase_add_test(tc, test_sprintf_x_4);
  tcase_add_test(tc, test_sprintf_x_5);
  tcase_add_test(tc, test_sprintf_x_6);
  tcase_add_test(tc, test_sprintf_x_7);
  tcase_add_test(tc, test_sprintf_x_8);
  tcase_add_test(tc, test_sprintf_x_9);
  tcase_add_test(tc, test_sprintf_x_10);
  tcase_add_test(tc, test_sprintf_x_11);
  tcase_add_test(tc, test_sprintf_x_12);
  return s;
}
