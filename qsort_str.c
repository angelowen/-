#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define len 1024
int compare(const void *a, const void *b) {
  return (strcmp((char *)a, (char *)b));
}
int main() {
  char a[len][len], i, j, cnt = 0;

  for (i = 0; i < 5; i++) {
    scanf("%s", a[i]);
  }
  qsort((void *)a, 5, sizeof(a[0]), compare);
  for (i = 0; i < 5; i++) {
    printf("%s\n", a[i]);
  }
  return 0;
}