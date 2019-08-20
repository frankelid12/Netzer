#include <bits/stdc++.h>
using namespace std;
const int N = 60;
const long double PI = acos(-1.);
long double a[N];
int main() {
  int r;
  cin >> r;
  for (int i = 0; i < 26; i++) {
    char x;
    long double v;
    cin >> x >> v;
    a[x - 'A'] = v;
  }
  cin.ignore();
  string S;
  getline(cin, S);
  //cout << S << endl;
  long double sol = 0;
  int P = -1;
  for (int i = 0; i < S.size(); i++) {
    int x = -1;
    if ('a' <= S[i] && S[i] <= 'z') {
      x = S[i] - 'a';
    } else if ('A' <= S[i] && S[i] <= 'Z') {
      x = S[i] - 'A';
    } else {
      continue;
    }
    if (P == -1) {
      sol += r;
    } else {
      long double calc = abs(a[x] - a[P]);
      calc = min(calc, 360 - calc);
      calc = calc * PI / 180;
      long double d = r * sqrt(2 * (1 - cos(calc)));
      sol += d;
    }
    P = x;
  }
  printf("%lld\n", (long long) (ceil(sol) + 0.5));
  return 0;
}