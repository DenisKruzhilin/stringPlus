#include "s21_string.h"

#ifdef __linux__
#define ERR_FIRST 0
#define ERR_LAST 133
static char *linux_err[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error",
};
#elif defined(__APPLE__) && defined(__MACH__)  //  <- вызов на мак исправлено
#define ERR_FIRST 0
#define ERR_LAST 106
static char *mac_err[] = {
    "Undefined error: 0",  // <- исправлено 107 заменены ошибки
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"};
#endif

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t i = 0;
  char *res = S21_NULL;
  while ((i < n) && (res == S21_NULL)) {
    if (*((char *)str + i) == c) res = (char *)str + i;
    ++i;
  }
  return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  s21_size_t i = 0;
  int res = 0;
  while ((i < n) && (!res)) {
    if (*((char *)str1 + i) != *((char *)str2 + i))
      res = *((char *)str1 + i) - *((char *)str2 + i);
    ++i;
  }
  return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n) {
    *((char *)dest + i) = *((char *)src + i);
    ++i;
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n) {
    *((char *)str + i) = c;
    ++i;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  unsigned int i, j;
  i = 0;
  while (dest[i]) ++i;
  j = 0;
  while ((j < n) && (src[j])) {
    dest[i] = src[j];
    ++i;
    ++j;
  }
  dest[i] = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  int i = 0;
  while (str[i] && str[i] != c) ++i;
  return c == str[i] ? (char *)str + i : S21_NULL;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  s21_size_t i = 0;
  while ((i < n) && (!res)) {
    if (str1[i] != str2[i])
      res = str1[i] - str2[i];
    else
      ++i;
  }
  return res;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  for (i = 0; (i < n) && src[i]; i++) dest[i] = src[i];
  for (; i < n; i++) dest[i] = '\0';
  return dest;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t count = 0;
  while (str[count]) ++count;
  return count;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  int i = 0;
  const char *res;
  while (str1[i] && (s21_strchr(str2, str1[i]) == S21_NULL)) ++i;
  if (str1[i])
    res = str1 + i;
  else
    res = S21_NULL;
  return (char *)res;
}

char *s21_strrchr(const char *str, int c) {
  const char *res;
  int j = s21_strlen(str);
  while ((j >= 0) && (str[j] != c)) --j;
  if (j == -1)
    res = S21_NULL;
  else
    res = str + j;
  return (char *)res;
}

char *s21_strstr(const char *haystack, const char *needle) {
  unsigned int i = 0;
  int res = -1;
  while (haystack[i] && (res == -1)) {
    unsigned int j = 0;
    unsigned int i1 = i;
    while ((haystack[i1] == needle[j]) && (haystack[i1]) && (needle[j])) {
      ++i1;
      ++j;
    }
    if (!needle[j]) res = i;
    ++i;
  }
  if (res != -1)
    return (char *)haystack + res;
  else
    return S21_NULL;
}

int s21_strspn(const char *buf, const char *delim) {
  int i = 0;
  int flag = 1;
  int count = 0;
  while (buf[i] && flag) {
    flag = 0;
    int j = 0;
    while (delim[j]) {
      if (buf[i] == delim[j]) flag = 1;
      ++j;
    }
    if (flag) ++count;
    ++i;
  }
  return count;
}

int s21_strcspn(const char *buf, const char *delim) {
  int i = 0;
  int flag = 0;
  int count = 0;
  while (buf[i] && (!flag)) {
    int j = 0;
    while (delim[j]) {
      if (buf[i] == delim[j]) flag = 1;
      ++j;
    }
    if (!flag) ++count;
    ++i;
  }
  return count;
}

char *s21_strtok(char *str, const char *delim) {
  static char *buffer;

  if (str != S21_NULL) buffer = str;
  buffer += s21_strspn(buffer, delim);
  int flag = 1;
  char *tokenBegin = buffer;
  if (*buffer == '\0') {
    tokenBegin = S21_NULL;
    flag = 0;
  }

  if (flag) {
    buffer += s21_strcspn(buffer, delim);

    if ((*buffer) != '\0') {
      *buffer = '\0';
      ++buffer;
    }
  }
  return tokenBegin;
}

char *s21_strerror(int errnum) {
  static char result[256];
  s21_memset(result, '\0', 256);
  if ((errnum < ERR_FIRST) || (errnum > ERR_LAST)) {
#ifdef __linux__
    s21_strncat(result, "Unknown error ", 15);
#elif defined(__APPLE__) && defined(__MACH__)
    s21_strncat(result, "Unknown error: ", 16);
#endif
    if (errnum < 0) {
      s21_strncat(result, "-", 1);
      errnum *= (-1);
    }
    int capacity = 20;
    char *temp = malloc(capacity);
    s21_litoa((unsigned long int)errnum, &temp, &capacity);
    s21_strncat(result, temp, s21_strlen(temp));
    free(temp);
  } else {
#ifdef __linux__
    s21_strncpy(result, linux_err[errnum], s21_strlen(linux_err[errnum]));
#elif defined(__APPLE__) && defined(__MACH__)
    s21_strncpy(result, mac_err[errnum], s21_strlen(mac_err[errnum]));
#endif
  }
  return result;
}
