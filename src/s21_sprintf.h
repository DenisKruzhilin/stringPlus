#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include "s21_string.h"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define FLAGS_LIST "+- #0"
#define WIDTHorPRESISION_LIST "*1234567890"
#define LENGTH_LIST "hlL"
#define SPECIFICATORS_LIST "cdieEfgGosuxXpn"

typedef struct specificator {
  char flag[6];
  int width;
  int precision;
  char length;
  char spec;
  char specsym;
} sr;

int s21_sprintf(char* buf, const char* format, ...);
int s21_copy_to_buf(char* buf, const char* string, va_list* p_args);
void s21_format_processing(char* buf, const char* string, va_list* p_args,
                           s21_size_t* ptr_i, s21_size_t* ptr_j);
void s21_strcatback(char* buf, s21_size_t* ptr_j, const char* string,
                    size_t i_begin, size_t i_end);
void s21_o_u_x_p_to_buf(unsigned long int a, char* buf, sr option,
                        s21_size_t* ptr_j);
void s21_d_to_buf(long int a, char* buf, sr option, s21_size_t* ptr_j);
void s21_u_to_buf(unsigned long int a, char* buf, sr option, s21_size_t* ptr_j);
void s21_x_to_buf(unsigned long int a, char* buf, sr option, s21_size_t* ptr_j);
void s21_o_to_buf(unsigned long int a, char* buf, sr option, s21_size_t* ptr_j);
void copy_u_d_x_o(char* buf, char** temp, int* capacity, int sign, sr option,
                  s21_size_t* ptr_j);
void s21_f_to_buf(long double a, char* buf, sr option, s21_size_t* ptr_j);
void s21_eE_to_buf(long double a, char* buf, sr option, s21_size_t* ptr_j);
void s21_s_to_buf(va_list* p_args, char* buf, sr option, s21_size_t* ptr_j);
void s21_lc_to_buf(wchar_t a, char* buf, sr option, s21_size_t* ptr_j);
void s21_c_to_buf(char a, char* buf, sr option, s21_size_t* ptr_j);
void s21_copy(char* buf, char** temp, int* capacity, sr option,
              s21_size_t* ptr_j, s21_size_t size);
void s21_parse_specificator(const char* str, s21_size_t* i_begin, sr* options,
                            va_list* p_args);
void s21_add_sign(char* str, int sign, char* flags);
void s21_add_prefix(char* str, char spec);
void s21_add_precision(char** str, int* capacity, s21_size_t size,
                       int precision);
void s21_add_width_forward(char** str, int* capacity, s21_size_t size,
                           int width, char specsym);
void s21_add_width_end(char** str, int* capacity, s21_size_t size, int width);

#endif
