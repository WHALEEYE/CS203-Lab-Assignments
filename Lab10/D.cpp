#pragma GCC optimize("O2")
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int st;
  int ed;
  long long weight;
};

struct GraphNode {
  int root;
  int idx;
  int pt;
  GraphNode(int idx, int pt) : idx(idx), root(idx), pt(pt) {}
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

bool comp(Edge *a, Edge *b) { return a->weight > b->weight; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, max;
  long long sum = 0, pt;
  cin >> n >> m;
  GraphNode **grp = new GraphNode *[n * m];
  Edge *chosen;
  for (int i = 0; i < n * m; i++) {
    cin >> pt;
    grp[i] = new GraphNode(i, pt);
  }

  cout << sum;
  return 0;
}