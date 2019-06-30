#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 1010

// polynomial multiplication
int mult(int a[], int na, int b[], int nb, int c[]) {
  int i, j;
  for (i = 0; i <= na + nb; i++) c[i] = 0;
  for (i = 0; i <= na; i++)
    for (j = 0; j <= nb; j++) c[i + j] += a[i] * b[j];
  return (na + nb);
}

int main() {
  int i, j, n, ncase, k, d;
  int res[N], p[N], temp[N];
  //   freopen("ar02_test.in", "r", stdin);
  //   freopen("ar02_test.out", "w", stdout);
  scanf("%d", &ncase);
  while (ncase--) {
    scanf("%d%d%d%d", p + 2, p + 1, p, &d);  // d is 次方
    n = 2;
    for (i = 0; i < 3; i++) res[i] = p[i];
    for (i = 1; i < d; i++) {
      n = mult(res, n, p, 2, temp);
      for (j = 0; j <= n; j++) res[j] = temp[j];
    }
    // output
    for (i = n; i > 0; i--) {
      printf("%d ", res[i]);
    }
    printf("%d\n", res[0]);
  }
}