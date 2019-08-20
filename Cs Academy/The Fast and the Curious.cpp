#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
vector< int > Narr, low, T, visited, arra[N];
bool C[N];
int Cnt;
void tarjanSCCAlgorithm(int v, int prev = -1) {
  low[v] = Narr[v] = ++Cnt;
  visited[v] = 1;
  T.push_back(v);
  for(auto u : arra[v]) {
    if (u == prev) continue;
    if(Narr[u] == -1)
      tarjanSCCAlgorithm(u, v), low[v] = min(low[v], low[u]);
    if(visited[u])
      low[v] = min(low[v], Narr[u]);
  }
  if(low[v] == Narr[v]) {
    vector<int> Narr;
    while(1) {
      int u = T.back(); T.pop_back(); visited[u] = 0;
      Narr.push_back(u);
      if(u == v)
        break;
    }
    if (Narr.size() > 2) {
      for (auto it : Narr) C[it] = 1;
    }
  }
}
int main() {
  int n, m;
  Cnt = 0;
  scanf("%d %d", &n, &m);
  Narr.assign(n + 1, -1);
  low.assign(n + 1, 0);
  visited.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    arra[u].push_back(v);
    arra[v].push_back(u);
  }
  for(int i = 1; i <= n; i++)
    if(Narr[i] == -1)
      tarjanSCCAlgorithm(i);
  for (int i = 1; i <= n; i++) if (C[i] == 0) printf("%d\n", i);
  return 0;
}