#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
struct Edge {
  int from, to, capacity, flow, index;
  Edge(int from, int to, int capacity, int flow, int index) :
    from(from), to(to), capacity(capacity), flow(flow), index(index) {}
};
struct Dedge {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> parent;
  vector<int> Q;
  Dedge(int N) : N(N), G(N), parent(N), Q(N) {}
  void AddEdge(int from, int to, int capacity) {
    G[from].push_back(Edge(from, to, capacity, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }
  long long Bflow(int s, int t) {
    fill(parent.begin(), parent.end(), (Edge *) NULL);
    parent[s] = &G[0][0] - 1;
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
    Edge &e = G[x][i];
    if (!parent[e.to] && e.capacity - e.flow > 0) {
      parent[e.to] = &G[x][i];
      Q[tail++] = e.to;
    }
      }
    }
    if (!parent[t]) return 0;
    long long tflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != parent[s]; e = parent[e->from]) {
    if (!e) { amt = 0; break; }
    amt = min(amt, e->capacity - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != parent[s]; e = parent[e->from]) {
    e->flow += amt;
    G[e->to][e->index].flow -= amt;
      }
      tflow += amt;
    }
    return tflow;
  }
  long long GetMaxFlow(int s, int t) {
    long long tflow = 0;
    while (long long flow = Bflow(s, t))
      tflow += flow;
    return tflow;
  }
};
const int N = 205;
int Not[N][N];
int main() {
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 1; i <= n; i++) {
    Not[i][i] = 1;
    string buf, s;
    getline(cin, buf);
    stringstream ss(buf);
    while (ss >> s) {
      Not[i][atoi(s.c_str()) + 1] = 1;
    }
  }
  int nodes = 2 * n + 2;
  Dedge dedge(nodes);
  for (int i = 1; i <= n; i++) {
    dedge.AddEdge(0, i, 1);
    dedge.AddEdge(n + i, nodes - 1, 1);
    for (int j = 1; j <= n; j++) {
      if (!Not[i][j]) {
        dedge.AddEdge(i, n + j, 1);
      }
    }
  }
  cout << n - dedge.GetMaxFlow(0, nodes - 1) << endl;
  return 0;
}