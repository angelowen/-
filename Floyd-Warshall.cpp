#include <bits/stdc++.h>
using namespace std;
int w[9][9];       // 一張有權重的圖
int d[9][9];       // 最短路徑長度
int medium[9][9];  // 由i點到j點的路徑，其中繼點為medium[i][j]。

void Floyd_Warshall() {
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) {
      d[i][j] = w[i][j];
      medium[i][j] = -1;  // 預設為沒有中繼點
    }

  for (int i = 0; i < 9; i++) d[i][i] = 0;

  for (int k = 0; k < 9; k++)
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
          medium[i][j] = k;  // 由i點走到j點經過了k點
        }
}

// 這支函式並不會印出起點和終點，必須另行印出。
void find_path(int i, int j)  // 印出由i點到j點的最短路徑
{
  if (medium[i][j] == -1) return;  // 沒有中繼點就結束

  find_path(i, medium[i][j]);  // 先把前面的路徑都印出來
  cout << medium[i][j];        // 再把中繼點印出來
  find_path(medium[i][j], j);  // 最後把後面的路徑都印出來
}