    
#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int w[N], f[N], arr[N];
int main() {
  int num_of_test_cases;
  scanf("%d", &num_of_test_cases);
  while (num_of_test_cases--) {
    memset(arr, 0, sizeof(arr));
    int c,n;
    scanf("%d %d", &c, &n);
    for (int i = 0; i < n; i++) scanf("%d %d", w + i, f + i);
    for (int i = 0; i < n; i++) {
      for (int j = c; j >= w[i]; j--) {
        arr[j] = max(arr[j], arr[j-w[i]] + f[i]);
      }
    }
    int sol = 0;
    for (int i = 0; i <= c; i++) sol = max(sol, arr[i]);
    cout << sol << endl;
  }
  return 0;
}