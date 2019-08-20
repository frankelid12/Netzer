#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int n, m, k;
char carr[N + 2][N + 2];
typedef pair<int,int> pairp;
pairp arah[8] = {make_pair(0,-1), make_pair(-1,-1), make_pair(-1,0),make_pair(-1,1),make_pair(0,1),make_pair(1,1),make_pair(1,0),make_pair(1,-1)};
struct grid{
  char gridcarr[N + 2][N + 2];
  grid(){
    memset(gridcarr, 0, sizeof gridcarr);
  } 
  grid& operator=(const grid& g){
    for(int i = 0;i < n; ++i) for(int j = 0;j < m; ++j){
      this->gridcarr[i][j] = g.gridcarr[i][j];
    }
    return (*this);
  }
  bool operator<(const grid& g) const{
    for(int i = 0;i < n; ++i){
      for(int j = 0;j < m; ++j){
        if(this->gridcarr[i][j] != g.gridcarr[i][j]) return this->gridcarr[i][j] < g.gridcarr[i][j];
      }
    }
    return false;
  }
  bool operator>(const grid& g) const{
    for(int i = 0;i < n; ++i){
      for(int j = 0;j < m; ++j){
        if(this->gridcarr[i][j] != g.gridcarr[i][j]) return this->gridcarr[i][j] > g.gridcarr[i][j];
      }
    }
    return false;
  }
  bool operator==(const grid& g) const{
     for(int i = 0;i < n; ++i){
      for(int j = 0;j < m; ++j){
        if(this->gridcarr[i][j] != g.gridcarr[i][j]) return false;
      }
    }
    return true;
  }
} gridI;
vector<grid> gvec;
map<grid, int> gMAP;
bool valid(int x, int y){
  return x >= 0 && y >= 0 && x < n && y < m;
}
int main(){
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0;i < n; ++i) {
    scanf("%s", carr[i]);
    for(int j = 0;j < m; ++j) gridI.gridcarr[i][j] = carr[i][j];
  }
  gvec.push_back(gridI);
  gMAP[gridI] = 0;
  int gid = 1;
  int lastcycle = -1;
  for(gid = 0;gid < k && lastcycle == -1; ++gid){
    grid G;
    for(int i = 0;i < n; ++i) for(int j = 0;j < m; ++j){
      bool deg = gvec[gid].gridcarr[i][j] == '-';
      int lifeg = 0, death = 0;
      for(int x = 0;x < 8; ++x){
        pairp tmp = make_pair(i + arah[x].first, j + arah[x].second);
        if(tmp.first < 0) tmp.first += n;
        else if(tmp.first >= n) tmp.first -= n;
        if(tmp.second < 0) tmp.second += m;
        else if(tmp.second >= m) tmp.second -= m; 
        if(gvec[gid].gridcarr[tmp.first][tmp.second] == '*') lifeg++;
        else death++;
      }
      if(deg){
        G.gridcarr[i][j] = (lifeg == 3) ? '*' : '-';
      }
      else{
        G.gridcarr[i][j] = (lifeg >= 2 && lifeg <= 3) ? '*' : '-';
      }
    }
    if(gMAP.count(G)){
      lastcycle = gMAP[G];
    }
    else{
      gMAP[G] = gid + 1;
      gvec.push_back(G);
    }
  }
  grid sol;
  if(lastcycle == -1){
    sol = gvec[k];
  }
  else{
    int gcurr = gid - lastcycle;
    int sadd = (k - gid) % gcurr;
    sol = gvec[lastcycle + sadd];
  }
  for(int i = 0;i < n; ++i) {
    for(int j = 0;j < m; ++j){
      printf("%c", sol.gridcarr[i][j]);
    }
    puts("");
  }
  return 0;
}