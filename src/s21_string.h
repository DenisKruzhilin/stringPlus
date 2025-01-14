#ifndef S21_STRING_H
#define S21_STRING_H

#define S21_NULL ((void *)0)
typedef unsigned long long s21_size_t;

#include <stdlib.h>

#include "s21_additional_sprintf.h"
#include "s21_part5.h"
#include "s21_sprintf.h"

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
int s21_strspn(const char *buf, const char *delim);
int s21_strcspn(const char *buf, const char *delim);
char *s21_strtok(char *str, const char *delim);
char *s21_strerror(int errnum);

#endif
