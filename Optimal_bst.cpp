#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 251;
const int INF = 10000000;

int main() {
  int n;
  int p[N];
  int sum[N], w[N][N];
  int dp[N][N];

  while (cin >> n) {
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      dp[i][i] = 0;
    }

    sum[0] = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + p[i];
    for (int i = 1; i <= n; i++)
      for (int j = i; j <= n; j++) w[i][j] = sum[j] - sum[i - 1];
    //為了方便實作
    for (int i = 1; i <= n; i++) {
      dp[i][i - 1] = 0;
      w[i][i - 1] = 0;
    }
    dp[n + 1][n] = 0;
    w[n + 1][n] = 0;
    // for (int i = 0; i <= n; i++) {
    //   for (int j = 0; j <= n; j++) {
    //     cout << w[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    for (int d = 1; d <= n - 1; d++) {
      for (int l = 1, r = l + d; r <= n; l++, r++) {
        dp[l][r] = INF;

        for (int k = l; k <= r; k++) {
          dp[l][r] = min(dp[l][r], dp[l][k - 1] + dp[k + 1][r] + w[l][k - 1] +
                                       w[k + 1][r]);
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }

    cout << dp[1][n] << endl;
  }

  return 0;
}