#include <bits/stdc++.h>

using namespace std;

const int N = 1000, M = 10000;

vector<int> graph[N];

int a[M], b[M];
bool visited[M];

bool dfs_algorithm(int vertix, int par = -1) {
  if (visited[vertix])
    return true;
  visited[vertix] = 1;
  for (int edg : graph[vertix]) if (edg != par) {
    int u = vertix ^ a[edg] ^ b[edg];
    if (dfs_algorithm(u, edg))
      return true; 
  }
  return false;
}

int main() {
  int j;
  scanf("%d", &j);
  while (j--) {
    int n, m;
    scanf("%d %d", &n, &m);
    fill(visited, visited+n, false);
    for (int i = 0; i < n; i++)
      graph[i].clear();
    for (int i = 0; i < m; i++) {
      scanf("%d %d", a+i, b+i);
      graph[a[i]].push_back(i);
      graph[b[i]].push_back(i);
    }
    bool dfs_res = 0;
    for (int i = 0; i < n; i++) if (!visited[i])
      dfs_res |= dfs_algorithm(i);
    puts(dfs_res ? "1" : "0");
  }
  return 0;
}