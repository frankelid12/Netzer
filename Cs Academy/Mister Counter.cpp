#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int a[N], p[N];
struct tree { 
  tree(int n) : n(n) {
    build_tree(1, 0, n - 1);
  }
  void build_tree(int p, int l, int r) {
    narr[p].resize(r - l + 1);
    if (l == r) {
      narr[p][0] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build_tree(p + p, l, mid);
    build_tree(p + p + 1, mid + 1, r);
    merge(narr[p+p].begin(), narr[p+p].end(), narr[p+p+1].begin(), narr[p+p+1].end(), narr[p].begin());
  }
  int find(int l, int r, int y) {
    return find(1, 0, n - 1, l, r, y);
  }
  int find(int p, int l, int r, int ll, int rr, int y) {
    if (ll <= l && r <= rr) return upper_bound(narr[p].begin(), narr[p].end(), y) - narr[p].begin();
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    return find(p + p, l, mid, ll, rr, y) + find(p + p + 1, mid + 1, r, ll, rr, y);
  }
  vector<int> narr[N << 2];
  int n;
};
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  tree T(n);
  p[0] = -1;
  for (int i = 0; i + 1 < n; i++) {
    if (i) p[i] = p[i - 1];
    if (a[i] < a[i + 1]) {
      p[i] = i;
    }
  }
  int T_times;
  scanf("%d", &T_times);
  while (T_times--) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    if (x == y) {
      puts("0");
    } else {
      if (p[y - 1] < x) {
        puts("0");
      } else {
        int sol = y - p[y - 1] + 1;
        if (sol % 2 == 0) {
          if (T.find(y - sol + 1, y, a[y - sol + 1]) != sol / 2) {
            sol--;
          }
        }
        printf("%d\n", sol);
      }
    }
  }
  return 0;
}