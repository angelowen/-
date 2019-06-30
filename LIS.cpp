#include <bits/stdc++.h>  //最長遞增子序列
using namespace std;
#define len 8
int s[len] = {-7, 10, 9, 2, 3, 8, 8, 6};
int length[len];
int pre[len];  // pre[x] 記錄 s[x] 是接在哪個數字後面
// 遞迴版本
void trace(int i) {
  if (pre[i] != -1) trace(pre[i]);
  cout << s[i] << ' ';
}
void LIS() {
  for (int i = 0; i < len; i++) length[i] = 1;
  // -1 代表 s[i] 是開頭數字，沒有接在其他數字後面。
  for (int i = 0; i < len; i++) pre[i] = -1;

  for (int i = 0; i < len; i++)
    for (int j = i + 1; j < len; j++)
      if (s[i] < s[j] && length[i] + 1 > length[j]) {
        length[j] = length[i] + 1;
        // s[j] 接在 s[i] 後面
        pre[j] = i;
      }

  int n = 0, pos = 0;
  for (int i = 0; i < len; i++)
    if (length[i] > n) {
      n = length[i];
      pos = i;
    }
  trace(pos);  // 印出一個LIS
}

int main() { LIS(); }
/*
void LIS() {
  // 初始化。每一個數字本身就是長度為一的 LIS。
  for (int i = 0; i < 5; i++) length[i] = 1;

  for (int i = 0; i < 5; i++)
    // 找出 s[i] 後面能接上哪些數字，
    // 若是可以接，長度就增加。
    for (int j = i + 1; j < 5; j++)
      if (s[i] < s[j]) length[j] = max(length[j], length[i] + 1);

  // length[] 之中最大的值即為 LIS 的長度。
  int n = 0;
  for (int i = 0; i < 5; i++) n = max(n, length[i]);
  cout << "LIS的長度是" << n;
}
* /