// SPDX-FileCopyrightText: 2024 Integral <integral@member.fsf.org>
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <string.h>
#include <stdio.h>
#include "my_printf.h"
#define BUFFER_SIZE 128

void my_itoa(int num, char *buffer, int radix) {
  static const char *num2char = "FEDCBA9876543210123456789ABCDEF";
  if ((radix != 8) && (radix != 10) && (radix != 16))
    return;

  char *curr = buffer;
  if ((num < 0 && radix == 10) || num > 0) {
    char *start = buffer;
    if (num < 0) {
      *curr++ = '-';
      start++;
    }
    do {
      char c = num2char[num % radix + 15];
      *curr++ = c;
      num /= radix;
    } while (num);

    *curr-- = '\0';
    while (start < curr) {
      char tmp = *start;
      *start++ = *curr;
      *curr-- = tmp;
    }
  } else {
    /*
      int -> arithmatic shift
      unsigned int -> logical shift
      uNum = num convert arithmatic shift to logical shift.
    */
    unsigned int mask;
    const unsigned int uNum = num;
    if (radix == 8) {
      mask = 03 << 30;
      *curr++ = num2char[((uNum & mask) >> 30) + 15];

      mask = 07 << 27;
      for (int i = 27; i >= 0; i -= 3) {
        *curr++ = num2char[((uNum & mask) >> i) + 15];
        mask >>= 3;
      }
    } else {
      mask = 0xF << 28;
      for (int i = 28; i >= 0; i -= 4) {
        *curr++ = num2char[((uNum & mask) >> i) + 15];
        mask >>= 4;
      }
    }
    *curr-- = '\0';
  }
}

int my_vsprintf(char *str, const char *fmt, va_list arg) {
  const char *pFmt = fmt;
  char *pStr = str;
  while (*pFmt != '\0') {
    if (*pFmt == '%') {
      switch (*(pFmt + 1)) {
      case 's':
        strcpy(pStr, va_arg(arg, char *));
        break;
      case 'd':
        my_itoa(va_arg(arg, int), pStr, 10);
        break;
      case 'o':
      case 'O':
        my_itoa(va_arg(arg, int), pStr, 8);
        break;
      case 'x':
      case 'X':
        my_itoa(va_arg(arg, int), pStr, 16);
        break;
      case 'c':
        *pStr++ = va_arg(arg, int);
        pFmt += 2;
        continue;
      }
      pStr += strlen(pStr);
      pFmt += 2;
    } else
      *pStr++ = *pFmt++;
  }
  return pStr - str - 1;
}

int my_printf(const char *fmt, ...) {
  char buffer[BUFFER_SIZE];
  memset(buffer, 0, sizeof(buffer));

  va_list args;
  va_start(args, fmt);
  int length = my_vsprintf(buffer, fmt, args);
  va_end(args);

  puts(buffer);
  return length;
}
