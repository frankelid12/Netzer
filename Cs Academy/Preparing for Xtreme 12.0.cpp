#include <bits/stdc++.h>
using namespace std;
vector<int> C[105];
int val[105], G[105];
const long long inf = 1e10;
long long arr[1 << 20];
map<string, int> MAP;
int n, P;
int get_map_val(string s) {
  if (MAP.count(s)) return MAP[s];
  MAP[s] = P++;
  return MAP[s];
}
long long dfs_algorithm(int M) {
  if (M + 1 == (1 << P)) return 0;
  if (arr[M] != -1) return arr[M];
  long long sol = inf;
  for (int i = 0; i < n; i++) {
    if ((M | G[i]) != M) {
      sol = min(sol, val[i] + dfs_algorithm(M | G[i]));
    }
  }
  return arr[M] = sol;
}
int main() {
  string str;
  while (getline(cin, str)) {
    stringstream ss(str);
    string num, buf;
    ss >> num;
    val[n] = atoi(num.c_str());
    while (ss >> buf) {
      int temp = get_map_val(buf);
      C[n].push_back(temp);
      G[n] |= (1 << temp);
    }
    n++;
  }
  memset(arr, -1, sizeof(arr));
  printf("%lld\n", dfs_algorithm(0));
  return 0;
}