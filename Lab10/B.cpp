#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int st;
  int ed;
};

struct GraphNode {
  int idx;
  int curidx;
  bool visited;
  vector<Edge *> nbs;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, u, v;
  cin >> n >> m;
  GraphNode **grp = new GraphNode *[n + 1];
  GraphNode **grpT = new GraphNode *[n + 1];
  for (int i = 1; i <= n; i++) {
    grp[i] = new GraphNode{i, 0, false};
    grpT[i] = new GraphNode{i, 0, false};
  }
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    grp[u]->nbs.push_back(new Edge{u, v});
    GraphNode *temp1 = grp[u];
    grpT[v]->nbs.push_back(new Edge{v, u});
    GraphNode *temp2 = grp[v];
  }

  GraphNode **stk = new GraphNode *[n];
  GraphNode *topE;
  int top = 0, num = 0;

  stk[top++] = grpT[1];
  grpT[1]->visited = true;
  while (top != 0) {
    topE = stk[top - 1];
    int size = topE->nbs.size();
    for (int i = topE->curidx; i < topE->nbs.size(); i++) {
      if (!grpT[topE->nbs[i]->ed]->visited) {
        topE->curidx = i;
        break;
      }
      if (i == topE->nbs.size() - 1) {
        topE->curidx = topE->nbs.size();
      }
    }
    if (topE->curidx < topE->nbs.size()) {
      stk[top] = grpT[topE->nbs[topE->curidx]->ed];
      grpT[topE->nbs[topE->curidx]->ed]->visited = true;
      top++;
    } else {
      num++;
      top--;
    }
  }
  if (num != n) {
    cout << "wawawa";
    return 0;
  }

  num = 0;
  stk[top++] = grp[1];
  grp[1]->visited = true;
  while (top != 0) {
    topE = stk[top - 1];
    for (int i = topE->curidx; i < topE->nbs.size(); i++) {
      if (!grp[topE->nbs[i]->ed]->visited) {
        topE->curidx = i;
        break;
      }
      if (i == topE->nbs.size() - 1) {
        topE->curidx = topE->nbs.size();
      }
    }
    if (topE->curidx < topE->nbs.size()) {
      stk[top] = grp[topE->nbs[topE->curidx]->ed];
      grp[topE->nbs[topE->curidx]->ed]->visited = true;
      top++;
    } else {
      num++;
      top--;
    }
  }
  if (num != n) {
    cout << "wawawa";
    return 0;
  }

  cout << "Bravo";
  return 0;
}