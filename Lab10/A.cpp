#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int end;
  int weight;
  bool visited;
};

struct GraphNode {
  int idx;
  bool visited;
  vector<Edge *> nbs;
  GraphNode(int idx) : idx(idx), visited(false) {}
};

bool comp(Edge *a, Edge *b) { return a->weight < b->weight; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, min, u, v, w;
  long long sum = 0;
  cin >> n >> m;
  GraphNode **grp = new GraphNode *[n + 1];
  Edge *chosen;
  for (int i = 1; i <= n; i++) {
    grp[i] = new GraphNode(i);
  }
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    grp[u]->nbs.push_back(new Edge{v, w});
    grp[v]->nbs.push_back(new Edge{u, w});
  }
  for (int i = 1; i <= n; i++) {
    sort(grp[i]->nbs.begin(), grp[i]->nbs.end(), comp);
  }
  bool stop = false;
  grp[1]->visited = true;
  while (!stop) {
    min = 10000000;
    stop = true;
    for (int i = 1; i <= n; i++) {
      if (grp[i]->visited) {
        for (int j = 0; j < grp[i]->nbs.size(); j++) {
          if ((!grp[grp[i]->nbs[j]->end]->visited) &&
              (!grp[i]->nbs[j]->visited)) {
            if (grp[i]->nbs[j]->weight < min) {
              stop = false;
              chosen = grp[i]->nbs[j];
              min = grp[i]->nbs[j]->weight;
            }
            break;
          }
        }
      }
    }
    if (!stop) {
      sum += min;
      grp[chosen->end]->visited = true;
      chosen->visited = true;
    }
  }
  cout << sum;
  return 0;
}