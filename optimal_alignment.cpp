#include <bits/stdc++.h>
using namespace std;
// char *ptr;
char s1[7 + 1] = {'0', 'C', 'T', 'T', 'A', 'A', 'C', 'T'};
char s2[8 + 1] = {'0', 'C', 'G', 'G', 'A', 'T', 'C', 'A', 'T'};
int n1 = 7, n2 = 8;
int match = 8, gap = -3;
int mis = -5;
int length[7 + 1][8 + 1];  // DP表格
int max_1(int a, int b, int c) {
  a = a > b ? a : b;
  c = a > c ? a : c;
  return c;
}
void LCS() {
  length[0][0] = 0;
  for (int i = 1; i <= n1; i++) length[i][0] = length[i - 1][0] + gap;
  for (int j = 1; j <= n2; j++) length[0][j] = length[0][j - 1] + gap;

  // 填表格：依照遞迴公式
  for (int i = 1; i <= n1; i++)
    for (int j = 1; j <= n2; j++)
      if (s1[i] == s2[j])
        length[i][j] = length[i - 1][j - 1] + match;
      else
        length[i][j] = max_1(length[i - 1][j] + gap, length[i][j - 1] + gap,
                             length[i - 1][j - 1] + mis);
  cout << "length of LCS:" << length[n1][n2];
//   for (int i = 0; i <= n1; i++) {
//     printf("\n");
//     for (int j = 0; j <= n2; j++) {
//       printf("%d ", length[i][j]);
//     }
//   }
// }
int main() { LCS(); }