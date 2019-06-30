#include <bits/stdc++.h>
using namespace std;
void Union(int x, int y) {
  fx = getfather(x);
  fy = getfather(y);
  if (fy != fx) father[fx] = fy;
}
bool same(int x, int y) { return getfather(x) == getfather(y); }
int getfather(int v) {
  if (father[v] == v)
    return v;
  else {
    father[v] = getfather(father[v]);  //路径压缩
    return father[v];
  }
}
void judge(int x, int y)

{
  fx = getfather(x);
  fy = getfather(y);
    if (rank[fx] > rank[fy])
      father[fy] = fx;
    else {
      father[fx] = fy;
      if (rank[fx] == rank[fy]) ++rank[fy];
      //重要的是祖先的rank，所以只用修改祖先的rank就可以了，子节点的rank不用管
      
    }
}
int main() {
  for (int i = 0; i < data; i++)
    Union(clue1, clue2)
        // #掃描最後有幾個獨立的小團體
        int sum = 0;
  for (int j = 0; j < ppl; j++)
    if (f[j] == j) sum += 1
  // print(sum)
}
