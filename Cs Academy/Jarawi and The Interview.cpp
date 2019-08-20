#include <bits/stdc++.h>
using namespace std;
const int N = 1e6*1.01;
char s[N];
int L[N][26];
int main() {
  scanf("%s", s);
  int ns = strlen(s);
  for (int i = 0; i < 26; i++) {
    L[0][i] = -1;
  }
  for (int i = 0; i < ns; i++) {
    if (i)
      for (int j = 0; j < 26; j++) {
        L[i][j] = L[i-1][j];
      }
    L[i][s[i]-'a'] = i;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int n = ns-1;
    scanf("%s", s);
    int m = strlen(s), sol = 0;
    for(int i = m-1; i >= 0; --i) {
      if (n < 0) break;
      n = L[n][s[i]-'a'];
      if (n < 0) break;
      sol++;
      n--;
    }
    printf("%d\n", sol);
  }
  return 0;
}