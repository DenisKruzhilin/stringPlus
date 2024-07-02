#include "s21_sprintf.h"

int s21_sprintf(char* buf, const char* format, ...) {
  va_list p_args;
  va_start(p_args, format);
  int res = s21_copy_to_buf(buf, format, &p_args);
  va_end(p_args);
  return res;
}

int s21_copy_to_buf(char* buf, const char* string, va_list* p_args) {
  s21_size_t i = 0, j = 0;
  for (; i < s21_strlen(string); ++i, ++j) {
    if (string[i] == '%' && string[i + 1] == '%') {
      buf[j] = string[i];
      ++i;
    } else if (string[i] == '%') {
      ++i;
      s21_format_processing(buf, string, p_args, &i, &j);
    } else
      buf[j] = string[i];
  }
  buf[j] = '\0';
  return j;
}

void s21_format_processing(char* buf, const char* string, va_list* p_args,
                           s21_size_t* ptr_i, s21_size_t* ptr_j) {
  s21_size_t i_begin = *ptr_i - 1;
  sr option = {{0, 0, 0, 0, 0, 0}, -1, -1, 0, 0, ' '};
  s21_parse_specificator(string, ptr_i, &option, p_args);
  if (s21_strchr((char*)option.flag, '0') && (option.spec != 's') &&
      (option.spec != 'c'))
    option.specsym = '0';
  if (s21_strchr(SPECIFICATORS_LIST, option.spec)) {
    switch (option.spec) {
      case 'c':
        if (option.length == 'l')
          s21_lc_to_buf(va_arg(*p_args, wchar_t), buf, option, ptr_j);
        else
          s21_c_to_buf(va_arg(*p_args, int), buf, option, ptr_j);
        break;
      case 'd':
        if (option.length == 'l')
          s21_d_to_buf(va_arg(*p_args, long int), buf, option, ptr_j);
        else
          s21_d_to_buf((long int)va_arg(*p_args, int), buf, option, ptr_j);
        break;
      case 'f':
        if (option.length == 'L')
          s21_f_to_buf(va_arg(*p_args, long double), buf, option, ptr_j);
        else
          s21_f_to_buf((long double)va_arg(*p_args, double), buf, option,
                       ptr_j);
        break;
      case 's':
        s21_s_to_buf(p_args, buf, option, ptr_j);
        break;
      case 'u':
      case 'x':
      case 'X':
      case 'o':
        if (option.length == 'l')
          s21_o_u_x_p_to_buf(va_arg(*p_args, unsigned long int), buf, option,
                             ptr_j);
        else
          s21_o_u_x_p_to_buf((unsigned long int)va_arg(*p_args, unsigned int),
                             buf, option, ptr_j);
        break;
      case 'e':
      case 'E':
        if (option.length == 'L')
          s21_eE_to_buf(va_arg(*p_args, long double), buf, option, ptr_j);
        else
          s21_eE_to_buf((long double)va_arg(*p_args, double), buf, option,
                        ptr_j);
        break;
      case 'p':
        s21_o_u_x_p_to_buf(va_arg(*p_args, unsigned long int), buf, option,
                           ptr_j);
        break;
    }
  } else if (option.spec == '%')
    buf[*ptr_j] = '%';
  else
    s21_strcatback(buf, ptr_j, string, i_begin, *ptr_i);
}

void s21_strcatback(char* buf, s21_size_t* ptr_j, const char* string,
                    size_t i_begin, size_t i_end) {
  for (size_t i = i_begin; i <= i_end; ++i) buf[(*ptr_j)++] = string[i];
  --(*ptr_j);
}

void s21_parse_specificator(const char* str, s21_size_t* i_begin, sr* options,
                            va_list* p_args) {
  s21_size_t i = *i_begin;
  int flg_num = 0;
  while (s21_strchr(FLAGS_LIST, str[i]) && (flg_num < 5)) {
    options->flag[flg_num] = str[i++];
    ++flg_num;
  }
  if (str[i] == '*')
    options->width = va_arg(*p_args, int);
  else
    options->width = s21_atoi(str, i);
  while (s21_strchr(WIDTHorPRESISION_LIST, str[i])) ++i;
  if (str[i] == '.') {
    ++i;
    if ((s21_strchr(LENGTH_LIST, str[i])) ||
        (s21_strchr(SPECIFICATORS_LIST, str[i])))
      options->precision = 0;
    else if (str[i] == '*') {
      options->precision = va_arg(*p_args, int);
      ++i;
    } else {
      options->precision = s21_atoi(str, i);
      while (s21_strchr(WIDTHorPRESISION_LIST, str[i])) ++i;
    }
  }
  if (s21_strchr(LENGTH_LIST, str[i])) options->length = str[i++];
  options->spec = str[i];
  *i_begin = i;
  return;
}

void s21_o_u_x_p_to_buf(unsigned long int a, char* buf, sr option,
                        s21_size_t* ptr_j) {
  if (option.precision == -1) option.precision = 1;
  if (option.spec == 'u')
    s21_u_to_buf(a, buf, option, ptr_j);
  else if (option.spec == 'o')
    s21_o_to_buf(a, buf, option, ptr_j);
  else
    s21_x_to_buf(a, buf, option, ptr_j);
}

void s21_f_to_buf(long double a, char* buf, sr option, s21_size_t* ptr_j) {
  int sign = (a < -0.0000001) ? 1 : 0;
  a = (a < 0.000000001) ? (a * (-1)) : a;
  option.precision = (option.precision == -1) ? 6 : option.precision;
  int temp_cap = 10, tempfrac_cap = 10;
  char* temp = malloc(temp_cap);
  char* tempfrac = malloc(tempfrac_cap);
  if ((temp != S21_NULL) && (tempfrac != S21_NULL)) {
    long double intpart;
    long double fracpart = modfl(a, &intpart);
    unsigned long int b = (unsigned long int)intpart;
    int transfer =
        s21_ldtoa(fracpart, &tempfrac, &tempfrac_cap, option.precision);
    s21_litoa(b + transfer, &temp, &temp_cap);
    if (option.precision || s21_strchr((char*)option.flag, '#'))
      s21_strncat(temp, ".", 1);
    s21_save_strcat(&temp, &temp_cap, tempfrac);
    if (sign || (s21_strchr((char*)option.flag, '+')) ||
        (s21_strchr((char*)option.flag, ' ')))
      s21_add_sign(temp, sign, (char*)option.flag);
    s21_size_t size = s21_strlen(temp);
    s21_copy(buf, &temp, &temp_cap, option, ptr_j, size);
  }
  free(temp);
  free(tempfrac);
}

void s21_eE_to_buf(long double a, char* buf, sr option, s21_size_t* ptr_j) {
  int sign = (a < -0.000000001) ? 1 : 0;
  a = (a < -0.000000001) ? (a * (-1)) : a;
  option.precision = (option.precision == -1) ? 6 : option.precision;
  int pow = s21_normalize_mantiss(&a);
  int temp_cap = 10, tempfrac_cap = 10, pow_str_cap = 10;
  char* temp = malloc(temp_cap);
  char* tempfrac = malloc(tempfrac_cap);
  char* pow_str = malloc(pow_str_cap);
  if ((temp != S21_NULL) && (tempfrac != S21_NULL) && (pow_str != S21_NULL)) {
    long double intpart;
    long double fracpart = modfl(a, &intpart);
    unsigned long int b = (unsigned long int)intpart;
    int transfer =
        s21_ldtoa(fracpart, &tempfrac, &tempfrac_cap, option.precision);
    s21_litoa(b + transfer, &temp, &temp_cap);
    if (option.precision || s21_strchr((char*)option.flag, '#'))
      s21_strncat(temp, ".", 1);
    s21_save_strcat(&temp, &temp_cap, tempfrac);
    if (pow < 0) {
      s21_strncat(temp, (option.spec == 'e') ? "e-" : "E-", 2);
      pow *= (-1);
    } else
      s21_strncat(temp, (option.spec == 'e') ? "e+" : "E+", 2);
    if (pow < 10) s21_strncat(temp, "0", 1);
    s21_litoa((unsigned long int)pow, &pow_str, &pow_str_cap);
    s21_save_strcat(&temp, &temp_cap, pow_str);
    if (sign || (s21_strchr((char*)option.flag, '+')) ||
        (s21_strchr((char*)option.flag, ' ')))
      s21_add_sign(temp, sign, (char*)option.flag);
    s21_copy(buf, &temp, &temp_cap, option, ptr_j, s21_strlen(temp));
  }
  free(temp);
  free(tempfrac);
  free(pow_str);
}

void s21_d_to_buf(long int a, char* buf, sr option, s21_size_t* ptr_j) {
  if (option.precision == -1) option.precision = 1;
  int capacity = 10;
  char* temp = malloc(capacity);
  if (temp != S21_NULL) {
    int sign = (a < 0) ? 1 : 0;
    a = (a < 0) ? (a * (-1)) : a;
    s21_litoa(a, &temp, &capacity);
    copy_u_d_x_o(buf, &temp, &capacity, sign, option, ptr_j);
    free(temp);
  }
}

void s21_s_to_buf(va_list* p_args, char* buf, sr option, s21_size_t* ptr_j) {
  size_t size;
  char* temp;
  if ((option.length == 'l') || (option.length == 'L')) {
    const wchar_t* wstr = va_arg(*p_args, wchar_t*);
    if (wstr != S21_NULL) {
      int capacity = s21_wstrlen(wstr);
      temp = malloc(capacity + sizeof(wchar_t));
      if (temp != S21_NULL) size = (size_t)wcstombs(temp, wstr, capacity);
    }
  } else {
    const char* str = va_arg(*p_args, char*);
    if (str != S21_NULL) {
      size = s21_strlen(str);
      temp = malloc(size + 1);
      if (temp != S21_NULL) s21_strncpy(temp, str, size);
    }
  }
  int eff_size =
      (option.precision != -1) ? MIN((int)size, option.precision) : (int)size;
  if (s21_strchr((char*)option.flag, '-')) {
    for (int i = 0; i < eff_size; ++i) buf[(*ptr_j)++] = temp[i];
    for (int i = 0; i < option.width - eff_size; ++i)
      buf[(*ptr_j)++] = option.specsym;
    ;
    --(*ptr_j);
  } else {
    for (int i = 0; i < option.width - eff_size; ++i)
      buf[(*ptr_j)++] = option.specsym;
    for (int i = 0; i < eff_size; ++i) buf[(*ptr_j)++] = temp[i];

    --(*ptr_j);
  }
  free(temp);
}

void s21_c_to_buf(char a, char* buf, sr option, s21_size_t* ptr_j) {
  if (option.width == -1) option.width = 1;
  if (s21_strchr((char*)option.flag, '-')) {
    buf[(*ptr_j)++] = a;
    for (int i = 0; i < option.width - 1; ++i) buf[(*ptr_j)++] = option.specsym;
    ;
    (*ptr_j)--;
  } else {
    for (int i = 0; i < option.width - 1; ++i) buf[(*ptr_j)++] = option.specsym;
    ;
    buf[(*ptr_j)] = a;
  }
}

void s21_lc_to_buf(wchar_t a, char* buf, sr option, s21_size_t* ptr_j) {
  char tmp[10] = {0};
  int size = wctomb((char*)tmp, a);
  if (option.width == -1) option.width = size;
  if (s21_strchr((char*)option.flag, '-')) {
    buf[*ptr_j] = '\0';
    s21_strncat(buf, tmp, size);
    *ptr_j += size;
    for (int i = 0; i < option.width - size; ++i)
      buf[(*ptr_j)++] = option.specsym;
    ;
    (*ptr_j)--;
  } else {
    for (int i = 0; i < option.width - size; ++i)
      buf[(*ptr_j)++] = option.specsym;
    ;
    buf[*ptr_j] = '\0';
    s21_strncat(buf, tmp, size);
    *ptr_j += size - 1;
  }
}

void s21_o_to_buf(unsigned long int a, char* buf, sr option,
                  s21_size_t* ptr_j) {
  int capacity = 10;
  char* temp = malloc(capacity);
  if (temp != S21_NULL) {
    s21_dec_to_oct(a, &temp, &capacity);
    copy_u_d_x_o(buf, &temp, &capacity, 0, option, ptr_j);
    free(temp);
  }
}

void s21_x_to_buf(unsigned long int a, char* buf, sr option,
                  s21_size_t* ptr_j) {
  int capacity = 10;
  char* temp = malloc(capacity);
  if (temp != S21_NULL) {
    s21_dec_to_hex(a, &temp, &capacity, (option.spec == 'X') ? 1 : 0);
    copy_u_d_x_o(buf, &temp, &capacity, 0, option, ptr_j);
    free(temp);
  }
}

void s21_u_to_buf(unsigned long int a, char* buf, sr option,
                  s21_size_t* ptr_j) {
  int capacity = 10;
  char* temp = malloc(capacity);
  if (temp != S21_NULL) {
    s21_litoa(a, &temp, &capacity);
    copy_u_d_x_o(buf, &temp, &capacity, 0, option, ptr_j);
    free(temp);
  }
}

void copy_u_d_x_o(char* buf, char** temp, int* capacity, int sign, sr option,
                  s21_size_t* ptr_j) {
  if ((int)s21_strlen(*temp) < option.precision)
    s21_add_precision(temp, capacity, s21_strlen(*temp), option.precision);
  if ((s21_strchr("xXo", option.spec) && s21_strchr((char*)option.flag, '#') &&
       s21_strlen(*temp)) ||
      (option.spec == 'p'))
    s21_add_prefix(*temp, option.spec);
  if ((sign || (s21_strchr((char*)option.flag, '+')) ||
       (s21_strchr((char*)option.flag, ' '))) &&
      ((option.spec == 'd') || (option.spec == 'p')))
    s21_add_sign(*temp, sign, (char*)option.flag);
  int size = s21_strlen(*temp);
  s21_copy(buf, temp, capacity, option, ptr_j, size);
}

void s21_copy(char* buf, char** temp, int* capacity, sr option,
              s21_size_t* ptr_j, s21_size_t size) {
  if (s21_strchr((char*)option.flag, '-'))
    s21_add_width_end(temp, capacity, size, option.width);
  else
    s21_add_width_forward(temp, capacity, size, option.width, option.specsym);
  size_t size1 = s21_strlen(*temp);
  for (size_t i = 0; i < size1; ++i) buf[(*ptr_j)++] = (*temp)[i];
  --(*ptr_j);
}

void s21_add_sign(char* str, int sign, char* flags) {
  int size = s21_strlen(str);
  for (int i = size; i >= 0; --i) str[i + 1] = str[i];
  if (sign || s21_strchr(flags, '+'))
    str[0] = (sign) ? '-' : '+';
  else
    str[0] = ' ';
}

void s21_add_precision(char** str, int* capacity, s21_size_t size,
                       int precision) {
  int del = precision - (int)size;
  if (s21_possible_realloc(str, capacity, precision)) {
    for (int i = size; i >= 0; --i) (*str)[i + del] = (*str)[i];
    for (int i = 0; i < del; ++i) (*str)[i] = '0';
  }
}

void s21_add_prefix(char* str, char spec) {
  int del = (spec == 'o') ? 1 : 2;
  if (!((str[0] == '0') && (spec == 'o'))) {
    int size = s21_strlen(str);
    for (int i = size; i >= 0; --i) str[i + del] = str[i];
    str[0] = '0';
  }
  if (s21_strchr("xXp", spec)) str[1] = (spec == 'X') ? 'X' : 'x';
}

void s21_add_width_forward(char** str, int* capacity, s21_size_t size,
                           int width, char specsym) {
  int fir_is_sign = (s21_strchr("-+ ", (*str)[0])) ? 1 : 0;
  width = (width < (int)size) ? ((int)size) : width;
  int del = width - (int)size;
  if (s21_possible_realloc(str, capacity, size + del)) {
    for (int i = size; i >= 0; --i) (*str)[i + del] = (*str)[i];
    for (int i = 0; i < del; ++i) (*str)[i] = specsym;
    if (fir_is_sign && (specsym == '0')) s21_swap((*str) + 0, (*str) + del);
  }
}

void s21_add_width_end(char** str, int* capacity, s21_size_t size, int width) {
  width = (width < (int)size) ? ((int)size) : width;
  int i = size;
  for (; i < width && s21_possible_realloc(str, capacity, i); ++i)
    (*str)[i] = ' ';
  (*str)[i] = '\0';
}