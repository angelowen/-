#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
  int l, n;
  while (cin >> l && l != 0) {
    cin >> n;
    int dp[52][52] = {0};
    int *table = new int[n + 2];
    n++;
    table[0] = 0;
    table[n] = l;
    for (int i = 1; i < n; i++) cin >> table[i];
    int r, b, e, c, temp;
    for (r = 2; r <= n; r++) {   // r(range)是區間範圍
      for (b = 0; b < n; b++) {  // b(begin)是起始點，e(end)是終點
        e = b + r;
        if (e > n) break;
        dp[b][e] = INT_MAX;
        for (c = b + 1; c < e; c++) {
          temp = dp[b][c] + dp[c][e] + table[e] - table[b];
          if (temp < dp[b][e]) dp[b][e] = temp;
        }
      }
    }
    printf("The minimum cutting is %d.\n", dp[0][n]);
  }
  return 0;
}
