#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
long long preva[N + 5];
int d, n = 1;
int karr[N + 5] , dim[N + 5] , arr[N + 5] ;
vector<int> convert_dims(int x){
  vector<int> vec;
  int temp = x;
  for(int i = 0;i < d; ++i){
    vec.push_back(temp / karr[i]);
    temp %= karr[i];    
  }
  return vec;  
}
int to_int(const vector<int> vec){
  int sol = 0;
  for(int i = 0;i < d; ++i) sol += vec[i] * karr[i];
  return sol;
}
int main(){
  scanf("%d", &d);
  for(int i = 0;i < d; ++i) scanf("%d", &dim[i]), n *= dim[i];
  karr[d-1] = 1;
  for(int i = d - 2;i >= 0; --i) karr[i] = karr[i + 1] * dim[i + 1];
  for(int i = 0;i < n; ++i) {
    scanf("%d", &arr[i]);
    vector<int> dims = convert_dims(i);
    preva[i] = arr[i];
    for(int j = 1;j < (1 << d); ++j){
      long long M;
      if(__builtin_popcount(j) & 1) M = 1;
      else M = -1;
      vector<int> dims2 = dims;
      bool minus = false;
      for(int k = 0;k < d; ++k){
        if((1 << k) & j) dims2[k]--;
        if(dims2[k] < 0) minus = true;
      }
      if(minus) continue;
      preva[i] += M * preva[to_int(dims2)];
    }
  }
  int q;
  scanf("%d", &q);
  while(q--){
    vector<int> larr(d);
    vector<int> rarr(d);
    for(int i = 0;i < d; ++i) scanf("%d", &larr[i]), larr[i]--;
    for(int i = 0;i < d; ++i) scanf("%d", &rarr[i]), rarr[i]--;
    long long sol = 0;
    for(int i = 0;i < (1 << d); ++i){
      vector<int> vec;
      bool minus = false;
      for(int j = 0;j < d; ++j){
        if((1 << j) & i){
          vec.push_back(larr[j] - 1);
          if(larr[j] == 0) minus = true;
        }
        else{
          vec.push_back(rarr[j]);
        }
      }
      if(minus) continue;
      else{
        long long karr = __builtin_popcount(i) & 1 ? -1LL : 1LL;
        sol += karr * preva[to_int(vec)];
      }
    }
    printf("%lld\n", sol);
  }
  return 0;
}