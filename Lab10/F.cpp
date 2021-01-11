#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Path;
struct GraphNode;
struct Edge;

struct GraphNode {
  int idx;
  vector<Edge *> nbs;
};

struct Edge {
  GraphNode *ed;
  long long weight;
};

struct Path {
  GraphNode *end;
  long long length;
  int remain;
  friend bool operator<(Path a, Path b) { return a.length > b.length; };
};

Path *nil = new Path{NULL, -1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, p, k;
  int u, v, S, T;
  long long w;
  cin >> n >> m >> p >> k;
  priority_queue<Path> pq;
  GraphNode **grp = new GraphNode *[n + 1];
  Path **minLgh = new Path *[n + 1], temp_path;
  for (int i = 1; i <= n; i++) {
    grp[i] = new GraphNode{i};
    minLgh[i] = nil;
  }
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    grp[u]->nbs.push_back(new Edge{grp[v], w});
  }
  for (int i = 0; i < p; i++) {
    cin >> u >> v;
    grp[u]->nbs.push_back(new Edge{grp[v], 0});
  }
  cin >> S >> T;
  temp_path = Path{grp[S], 0, k};
  pq.push(temp_path);
  Path topE;
  GraphNode *endNode;
  while (!pq.empty()) {
    topE = pq.top();
    pq.pop();
    endNode = topE.end;
    if (minLgh[endNode->idx] != nil &&
        minLgh[endNode->idx]->length <= topE.length &&
        minLgh[endNode->idx]->remain >= topE.remain) {
      continue;
    } else {
      if (minLgh[endNode->idx] == nil ||
          minLgh[endNode->idx]->length > topE.length) {
        minLgh[endNode->idx] = new Path{endNode, topE.length, topE.remain};
      }
      for (int i = 0; i < endNode->nbs.size(); i++) {
        if (endNode->nbs[i]->weight != 0) {
          pq.push(Path{endNode->nbs[i]->ed,
                       topE.length + endNode->nbs[i]->weight, topE.remain});
        } else if (topE.remain > 0) {
          pq.push(Path{endNode->nbs[i]->ed, topE.length, topE.remain - 1});
        }
      }
    }
  }
  cout << minLgh[T]->length;
  return 0;
}