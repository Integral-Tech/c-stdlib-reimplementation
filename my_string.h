// SPDX-FileCopyrightText: 2024 Integral <integral@member.fsf.org>
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <stddef.h>
typedef unsigned char uint8_t;

char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, size_t size);
int my_strncmp(const char *s1, const char *s2, size_t size);
size_t my_strlen(const char *str);
void *my_memcpy(void *dest, const void *src, size_t size);
void *my_memset(void *dest, uint8_t data, size_t size);
int my_memcmp(const void *data1, const void *data2, size_t size);
