#ifndef S21_ADDITIONAL_SPRINTF_H
#define S21_ADDITIONAL_SPRINTF_H

#include <stdlib.h>

#include "s21_string.h"

int s21_atoi(const char* str, unsigned int i);
void s21_litoa(unsigned long int a, char** str, int* capacity);
int s21_ldtoa(long double fracpart, char** tempfrac, int* capacity, int size);
void s21_cutfirst(char* str);
void s21_reverse_str(char* str);
void s21_swap(char* a, char* b);
void s21_dec_to_hex(unsigned long int a, char** str, int* capacity, int flag);
void s21_dec_to_oct(unsigned long int a, char** str, int* capacity);
int s21_possible_realloc(char** str, int* capacity, int i);
int s21_normalize_mantiss(long double* a);
char* s21_save_strcat(char** dest, int* capacity, const char* src);
int s21_wstrlen(const wchar_t* wstr);

#endif