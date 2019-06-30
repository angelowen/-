#include <bits/stdc++.h>
using namespace std;
struct Job {
  int start, finish, profit;
};

bool cmp(Job s1, Job s2) { return (s1.finish < s2.finish); }
int latestNonConflict(Job arr[], int i) {
  for (int j = i - 1; j >= 0; j--) {
    if (arr[j].finish <= arr[i - 1].start) return j;
  }
  return -1;
}
int findMaxProfitRec(Job arr[], int n) {
  if (n == 1) return arr[0].profit;
  int inclProf = arr[n - 1].profit;
  int i = latestNonConflict(arr, n);
  if (i != -1) {
    inclProf += findMaxProfitRec(arr, i + 1);
  }
  int exclProf = findMaxProfitRec(arr, n - 1);
  return max(inclProf, exclProf);
}

int main() {
  Job arr[] = {{7, 8, 1}, {8, 10, 6}, {8, 9, 5}, {9, 12, 6}, {10, 16, 12}, {13, 17, 8}};
  int n = sizeof(arr) / sizeof(arr[0]);
  sort(arr, arr + n, cmp);
  cout << "The optimal profit is " << findMaxProfitRec(arr, n);
  return 0;
}