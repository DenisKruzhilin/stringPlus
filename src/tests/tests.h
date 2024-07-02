#ifndef _TESTS_H_
#define _TESTS_H_

#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite *s21_strlen_suite(void);
Suite *s21_memchr_suite(void);
Suite *s21_memcmp_suite(void);
Suite *s21_memcpy_suite(void);
Suite *s21_memset_suite(void);
Suite *s21_strstr_suite(void);
Suite *s21_strchr_suite(void);
Suite *s21_strpbrk_suite(void);
Suite *s21_strncmp_suite(void);
Suite *s21_strncpy_suite(void);
Suite *s21_strncat_suite(void);
Suite *s21_strcspn_suite(void);
Suite *s21_strrchr_suite(void);
Suite *s21_strerror_suite(void);
Suite *s21_strtok_suite(void);

Suite *s21_sprintf_c_suite(void);
Suite *s21_sprintf_d_suite(void);
Suite *s21_sprintf_u_suite(void);
Suite *s21_sprintf_f_suite(void);
Suite *s21_sprintf_s_suite(void);
Suite *s21_sprintf_o_suite(void);
Suite *s21_sprintf_x_suite(void);
Suite *s21_sprintf_percent_suite(void);
Suite *s21_sprintf_e_suite(void);
Suite *s21_sprintf_p_suite(void);

Suite *s21_insert_suite(void);
Suite *s21_trim_suite(void);
Suite *s21_to_lower_suite(void);
Suite *s21_to_upper_suite(void);

#endif