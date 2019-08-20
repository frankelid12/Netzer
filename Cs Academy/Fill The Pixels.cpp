#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char s[N][N];
int ax_p[] = {1, -1, 0, 0};
int ay_p[] = {0, 0, 1, -1};
int ax_k[] = {-1, 1, -1, 1};
int ay_k[] = {1, 1, -1, -1};
int ax_b[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int ay_b[] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool visited[N][N];
int n, m;
bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}
void dfs_p(int i, int j) {
  if (visited[i][j]) return;
  visited[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    int x = i + ax_p[k];
    int y = j + ay_p[k];
    if (!valid(x, y)) continue;
    if (s[x][y] != '1') continue;
    dfs_p(x, y);
  }
}
void dfs_k(int i, int j) {
  if (visited[i][j]) return;
  visited[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    int x = i + ax_k[k];
    int y = j + ay_k[k];
    if (!valid(x, y)) continue;
    if (s[x][y] != '1') continue;
    dfs_k(x, y);
  }
}
void dfs_b(int i, int j) {
  if (visited[i][j]) return;
  visited[i][j] = 1;
  for (int k = 0; k < 8; k++) {
    int x = i + ax_b[k];
    int y = j + ay_b[k];
    if (!valid(x, y)) continue;
    if (s[x][y] != '1') continue;
    dfs_b(x, y);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    swap(n, m);
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    int a = 0, b = 0, c = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1' && !visited[i][j]) {
          dfs_p(i, j);
          a++;
        }
      }
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1' && !visited[i][j]) {
          dfs_k(i, j);
          b++;
        }
      }
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1' && !visited[i][j]) {
          dfs_b(i, j);
          c++;
        }
      }
    }
    printf("%d %d %d\n", a, b, c);
  }
  return 0;
}