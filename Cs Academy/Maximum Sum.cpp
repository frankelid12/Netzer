#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], n, arr[N];
int main() {
  int num_of_tests;
  scanf("%d",&num_of_tests);
  while (num_of_tests--){
    scanf("%d",&n);
    long long sol = 0;
    for (int i = 0;i < n; i++)
      scanf("%d", a+i);
    int l = 0, r = n-1;
    sort(a, a+n);
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < n; i++)
      arr[a[i]]++;
    while (arr[0]) a[l++] = 0, arr[0]--;
    bool le = 1;
    for (int i = 1; i < N; i++) {
      if (arr[i] > 1) {
        arr[i]--;
        a[r--] = i;
        while (arr[i] > 0) a[l++] = i, arr[i]--;
        le = 1;
      }
      else if (arr[i] == 1) {
        if (le)
          a[l++] = i;
        else
          a[r--] = i;
        le ^= 1;
      }
    }
    for (int k= 0; k + 1 < n; k++) {
      sol += 1LL * a[k] * a[k+1];
    }
    printf("%lld\n", sol);
    for (int j = 0; j < n; j++)
      printf("%d%c", a[j], j == n-1 ? '\n' : ' ');
  }
  return 0;
}