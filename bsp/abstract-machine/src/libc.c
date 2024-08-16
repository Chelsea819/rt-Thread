#include <klib.h>
#include <rtthread.h>

char *strchr(const char *s, int c) {
  // printf("s = %s\n",s);
  // printf("c = %d\n",c);
  assert(0);
  // return NULL;
}

char *strrchr(const char *s, int c) {
  // printf("s = %s\n",s);
  // printf("c = %d\n",c);
  assert(0);
  // return NULL;
}

char *strstr(const char *haystack, const char *needle) {
  return rt_strstr(haystack, needle);
}

long strtol(const char *restrict nptr, char **restrict endptr, int base) {
  assert(0);
}

char *strncat(char *restrict dst, const char *restrict src, size_t sz) {
  // printf("src = %s\n",src);
  // printf("sz = %ld\n",sz);
  assert(0);
  // return NULL;
}
