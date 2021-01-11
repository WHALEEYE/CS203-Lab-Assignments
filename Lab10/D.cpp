#pragma GCC optimize("O2")
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int v1;
  int v2;
  long long weight;
};

struct GraphNode {
  int prt;
  int idx;
  long long pt;
  GraphNode(int idx, long long pt) : idx(idx), prt(idx), pt(pt) {}
};

class BigHeap {
 public:
  int rear, con, curidx, max;
  Edge **hp, *temp;
  BigHeap(int con) : rear(0), con(con) { hp = new Edge *[con]; }

  ~BigHeap() { delete hp; }

  Edge *deleteTop() {
    if (rear == 0) {
      return NULL;
    }
    rear--;
    Edge *top = hp[0];
    hp[0] = hp[rear];
    curidx = 0;
    while (true) {
      if (2 * curidx + 1 >= rear) {
        break;
      }
      if (2 * curidx + 2 >= rear) {
        max = 2 * curidx + 1;
      } else {
        max = hp[2 * curidx + 1]->weight < hp[2 * curidx + 2]->weight
                  ? (2 * curidx + 2)
                  : (2 * curidx + 1);
      }
      if (hp[curidx]->weight < hp[max]->weight) {
        temp = hp[curidx];
        hp[curidx] = hp[max];
        hp[max] = temp;
        curidx = max;
      } else {
        break;
      }
    }
    return top;
  }

  void insertHeap(Edge *val) {
    curidx = rear;
    hp[rear++] = val;
    while (curidx > 0) {
      if (hp[curidx]->weight > hp[(curidx - 1) / 2]->weight) {
        temp = hp[curidx];
        hp[curidx] = hp[(curidx - 1) / 2];
        hp[(curidx - 1) / 2] = temp;
        curidx = (curidx - 1) / 2;
      } else {
        break;
      }
    }
  }
};

Edge *find(Edge *a) {
  Edge *x;
  while (true) {
    if () }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, max;
  long long sum = 0, pt;
  cin >> n >> m;
  GraphNode **grp = new GraphNode *[n * m];
  Edge *temp_edge;
  for (int i = 0; i < n * m; i++) {
    cin >> pt;
    grp[i] = new GraphNode(i, pt);
  }
  BigHeap *bg = new BigHeap(1000000);
  for (int i = 0; i < n * m; i++) {
    if (i % m != m - 1) {
      bg->insertHeap(new Edge{i, i + 1, grp[i]->pt * grp[i + 1]->pt});
    }
    if (i / m != n - 1) {
      bg->insertHeap(new Edge{i, i + m, grp[i]->pt * grp[i + m]->pt});
    }
  }
  while (bg->rear) {
    temp_edge = bg->deleteTop();
    if () {
    }
  }
  cout << sum;
  return 0;
}