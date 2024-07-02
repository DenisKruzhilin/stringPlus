#include "s21_part5.h"

void *s21_to_upper(const char *str) {
  char *new_str = calloc(s21_strlen(str) + 1, sizeof(char));
  if (new_str) {
    s21_size_t i = 0;
    for (; i < s21_strlen(str); ++i) {
      char a = str[i];
      if ((a >= 97) && (a <= 122)) a -= 32;
      new_str[i] = a;
    }
    new_str[i] = '\0';
  }
  return (void *)new_str;
}

void *s21_to_lower(const char *str) {
  char *new_str = calloc(s21_strlen(str) + 1, sizeof(char));
  if (new_str) {
    s21_size_t i = 0;
    for (; i < s21_strlen(str); ++i) {
      char a = str[i];
      if ((a >= 65) && (a <= 90)) a += 32;
      new_str[i] = a;
    }
    new_str[i] = '\0';
  }
  return (void *)new_str;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t str_size = s21_strlen(str);
  s21_size_t src_size = s21_strlen(src);
  char *new_str = calloc(str_size + src_size + 1, sizeof(char));
  if (new_str) {
    if (start_index > src_size) start_index = src_size;
    s21_size_t i = 0, j = 0;
    for (; i < start_index; ++i) new_str[i] = src[i];
    for (; i < start_index + str_size; ++i) {
      new_str[i] = str[j];
      ++j;
    }
    j = start_index;
    for (; i < str_size + src_size; ++i) {
      new_str[i] = src[j];
      ++j;
    }
    new_str[i] = '\0';
  }
  return (void *)new_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_str = S21_NULL;
  s21_size_t i_b = 0, i_e = s21_strlen(src) - 1;
  while (s21_strchr(trim_chars, src[i_b])) ++i_b;
  while (s21_strchr(trim_chars, src[i_e])) --i_e;

  if (i_e >= i_b) {
    new_str = calloc(i_e - i_b + 2, sizeof(char));
    if (new_str) {
      s21_size_t j = 0;
      for (s21_size_t i = i_b; i <= i_e; ++i) {
        new_str[j] = src[i];
        ++j;
      }
      new_str[j] = '\0';
    }
  }
  return (void *)new_str;
}