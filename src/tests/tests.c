#include "tests.h"

#include <stdio.h>

int main(void) {
  int fail = 0;
  Suite *s[] = {
      s21_strlen_suite(),    s21_memchr_suite(),    s21_memcmp_suite(),
      s21_memcpy_suite(),    s21_strstr_suite(),    s21_strchr_suite(),
      s21_strpbrk_suite(),   s21_strncmp_suite(),   s21_memset_suite(),
      s21_strncpy_suite(),   s21_strncat_suite(),   s21_strcspn_suite(),
      s21_strrchr_suite(),   s21_strerror_suite(),  s21_strtok_suite(),
      s21_insert_suite(),    s21_trim_suite(),      s21_to_lower_suite(),
      s21_to_upper_suite(),  s21_sprintf_c_suite(), s21_sprintf_d_suite(),
      s21_sprintf_u_suite(), s21_sprintf_f_suite(), s21_sprintf_s_suite(),
      s21_sprintf_x_suite(), s21_sprintf_o_suite(), s21_sprintf_percent_suite(),
      s21_sprintf_e_suite(), s21_sprintf_p_suite(), NULL};
  for (int i = 0; s[i] != NULL; i++) {
    SRunner *runner = srunner_create(s[i]);
    srunner_run_all(runner, CK_NORMAL);
    fail += srunner_ntests_failed(runner);
    srunner_free(runner);
  }
  printf("FAIL: %d\n", fail);
  return 0;
}