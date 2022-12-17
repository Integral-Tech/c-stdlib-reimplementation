#include "my_string.h"

char *my_strcpy(char *dest, const char *src) {
  if (!dest || !src)
    return dest; // judge whether dest or src is NULL

  const char *p = dest;
  do {
    *dest++ = *src++;
  } while (*src != '\0');

  return (char *)p;
}

char *my_strncpy(char *dest, const char *src, size_t size) {
  if (!dest || !src || !size)
    return dest; // judge whether dest/src is NULL, or the size equals 0

  const char *p = dest;
  do {
    *dest++ = *src++;
  } while (*src != '\0' && --size);

  return (char *)p;
}

int my_strncmp(const char *s1, const char *s2, size_t size) {
  if (!s1 || !s2 || !size)
    return -1;

  while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && size--) {
    s1++;
    s2++;
  }

  if (!size && *(s1 - 1) == *(s2 - 1))
    return 0;
  else
    return *s1 - *s2;
}

size_t my_strlen(const char *str) {
  if (!str)
    return 0;

  size_t length = 0;
  while (*str++ != '\0')
    length++;

  return length;
}

void *my_memcpy(void *dest, const void *src, size_t size) {
  if (!dest || !src || !size)
    return dest;

  const uint8_t *pSrc = (uint8_t *)src;
  uint8_t *pDest = (uint8_t *)dest;

  while (size--)
    *pDest = *pSrc;

  return dest;
}

void *my_memset(void *dest, uint8_t data, size_t size) {
  if (!dest || !size)
    return dest;

  uint8_t *pDest = (uint8_t *)dest;
  while (size--)
    *pDest++ = data;

  return dest;
}

int my_memcmp(const void *data1, const void *data2, size_t size) {
  if (!data1 || !data2 || !size)
    return -1;

  const uint8_t *pData1 = (uint8_t *)data1, *pData2 = (uint8_t *)data2;
  while (*pData1++ == *pData2++ && size--);

  return *pData1 - *pData2;
}
