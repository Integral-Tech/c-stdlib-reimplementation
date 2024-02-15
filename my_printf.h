// SPDX-FileCopyrightText: 2024 Integral <integral@member.fsf.org>
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <stdarg.h>

void my_itoa(int num, char *buffer, int radix);
int my_vsprintf(char *str, const char *fmt, va_list arg);
int my_printf(const char *fmt, ...);
