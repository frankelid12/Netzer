#include <bits/stdc++.h>
using namespace std;
const int N = 2510;
int m_arr[N << 2], l_arr[N <<2], n;
void build(int id = 1, int l = 0, int r = n) {
  m_arr[id] = l_arr[id] = 0;
  if (r - l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}
void push(int id) {
  if (l_arr[id] == 0) return;
  int il = id << 1, ir = il | 1;
  m_arr[il] += l_arr[id];
  l_arr[il] += l_arr[id];
  m_arr[ir] += l_arr[id];
  l_arr[ir] += l_arr[id];
  l_arr[id] = 0;
}
void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    m_arr[id] += v;
    l_arr[id] += v;
    return;
  }
  push(id);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  m_arr[id] = max(m_arr[il], m_arr[ir]);
}
char s[N];
vector<pair<int, int > > vector_pair;
int main() {
  int num_of_tests;
  scanf("%d", &num_of_tests);
  while (num_of_tests--) {
    int h, w;
    scanf("%d %d", &h, &w);
    int S = 0, D = 0;
    vector_pair.clear();
    int max_hw = 2 * max(h, w);
    for (int i = 0; i < h; i++) {
      scanf("%s", s);
      for (int j = 0; j < w; j++) {
        if (s[j] == '.') continue;
        if (s[j] == '1')
          S++;
        else if (s[j] == '2')
          D++;
        if (vector_pair.size() <= max_hw)
          vector_pair.push_back(make_pair(i, j));
      }
    }
    if (max_hw > 2 && vector_pair.size() > max_hw)
      puts("NO");
    else if (!(S == D || S == (D+1)))
      puts("NO");
    else {
      bool ok = 1;
      int M = min(h, w);
      for (int len = 3; len <= M && ok; len++) {
        n = w;
        build();
        int L = 0, R = 0;
        for (int i = 0; i + len <= h && ok; i++) {
          while (R < vector_pair.size() && vector_pair[R].first < i + len)
            update(max(0, vector_pair[R].second-len+1), min(w-len, vector_pair[R].second) + 1, +1), R++;
          while (L < R && vector_pair[L].first < i)
            update(max(0, vector_pair[L].second-len+1), min(w-len, vector_pair[L].second) + 1, -1), L++;
          ok &= m_arr[1] < len;
        }
      }
      puts(ok ? "YES" : "NO");
    }
  }
  return 0;
}