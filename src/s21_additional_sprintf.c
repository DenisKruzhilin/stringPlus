#include "s21_additional_sprintf.h"

int s21_atoi(const char* str, unsigned int i) {
  unsigned int i1;
  int a = 0;
  i1 = i;
  while ((str[i] >= '0') && (str[i] <= '9')) ++i;
  if (i != i1) {
    unsigned int bas = 1;
    --i;
    while (i >= i1) {
      a += (str[i] - '0') * bas;
      bas *= 10;
      --i;
    }
  }
  return a;
}

void s21_litoa(unsigned long int a, char** str, int* capacity) {
  int i = 0;
  if (a == 0)
    (*str)[i++] = '0';
  else {
    while ((a > 0) && s21_possible_realloc(str, capacity, i)) {
      (*str)[i++] = '0' + a % 10;
      a = a / 10;
    }
  }
  (*str)[i] = '\0';
  s21_reverse_str(*str);
  return;
}

void s21_reverse_str(char* str) {
  int n = s21_strlen(str);
  for (int i = 0; i < n / 2; ++i) s21_swap(str + i, str + n - i - 1);
}

void s21_swap(char* a, char* b) {
  char c = *a;
  *a = *b;
  *b = c;
}

void s21_cutfirst(char* str) {
  s21_size_t i = 0, size = s21_strlen(str);
  for (; i < size; ++i) str[i] = str[i + 1];
  str[i] = '\0';
}

int s21_ldtoa(long double fracpart, char** tempfrac, int* capacity, int size) {
  (*tempfrac)[0] = '0';
  int i = 1;
  for (; (i <= size) && s21_possible_realloc(tempfrac, capacity, i); ++i) {
    fracpart *= 10;
    int digit = (int)fracpart;
    fracpart -= digit;
    (*tempfrac)[i] = '0' + digit;
  }
  (*tempfrac)[i] = '\0';
  fracpart *= 10;
  int digit = (int)fracpart;
  if (digit >= 5) {
    int j = i - 1;
    (*tempfrac)[j] += 1;
    while ((*tempfrac)[j] > '9' && (j > 0)) {
      (*tempfrac)[j] = '0';
      --j;
      (*tempfrac)[j] += 1;
    }
  }
  int transfer = (*tempfrac)[0] - '0';
  s21_cutfirst(*tempfrac);
  return transfer;
}

void s21_dec_to_hex(unsigned long int a, char** str, int* capacity, int flag) {
  int temp_capacity = 100;
  char* temp1 = malloc(temp_capacity);
  if (temp1 != S21_NULL) {
    char* base = "0123456789abcdef";
    int i = 0;
    while ((a > 0) && s21_possible_realloc(&temp1, &temp_capacity, i)) {
      int j = a % 16;
      temp1[i++] = (flag && (base[j] > 57)) ? (base[j] - 32) : base[j];
      a = a / 16;
    }
    temp1[i--] = '\0';
    int j = 0;
    for (; (i >= 0) && s21_possible_realloc(str, capacity, j); ++j)
      (*str)[j] = temp1[i--];
    (*str)[j] = '\0';
    free(temp1);
  }
}

void s21_dec_to_oct(unsigned long int a, char** str, int* capacity) {
  int temp_capacity = 100;
  char* temp1 = malloc(temp_capacity);
  if (temp1 != S21_NULL) {
    char* base = "01234567";
    int i = 0;
    while ((a > 0) && s21_possible_realloc(&temp1, &temp_capacity, i)) {
      int j = a % 8;
      temp1[i++] = base[j];
      a = a / 8;
    }
    temp1[i--] = '\0';
    int j = 0;
    for (; (i >= 0) && s21_possible_realloc(str, capacity, j); ++j)
      (*str)[j] = temp1[i--];
    (*str)[j] = '\0';
    free(temp1);
  }
}

int s21_possible_realloc(char** str, int* capacity, int i) {
  int flag = 0, back;
  while (i + 5 > *capacity) {
    (*capacity) *= 2;
    *str = realloc(*str, *capacity);
    flag = 1;
  }
  if ((flag && (*str)) || (!flag))
    back = 1;
  else
    back = 0;
  return back;
}

int s21_normalize_mantiss(long double* a) {
  int pow = 0;
  if (*a > 9.99999999999) {
    while (!((*a > 0.99999999999) && (*a <= 9.99999999999))) {
      ++pow;
      (*a) /= 10;
    }
  } else if ((*a < 0.99999999999) && (!(fabsl(*a - 0) < 0.00000000001))) {
    while (!((*a > 0.99999999999) && (*a <= 9.99999999999))) {
      --pow;
      (*a) *= 10;
    }
  }
  return pow;
}

char* s21_save_strcat(char** dest, int* capacity, const char* src) {
  unsigned int i, j;
  i = 0;
  while ((*dest)[i]) ++i;
  j = 0;
  while (src[j] && s21_possible_realloc(dest, capacity, i)) {
    (*dest)[i] = src[j];
    ++i;
    ++j;
  }
  (*dest)[i] = '\0';
  return *dest;
}

int s21_wstrlen(const wchar_t* wstr) {
  int i = 0;
  while (wstr[i]) ++i;
  return (i * sizeof(wchar_t));
}