#include <cmath>
#include <iostream>
using namespace std;

struct Path {
  int idx;
  double time;
  double velo;
};

Path *nil = new Path{-1, -1, -1};

class SmallHeap {
 public:
  int rear, con, curidx, min;
  Path **hp, *temp;
  SmallHeap(int con) : rear(0), con(con) { hp = new Path *[con]; }

  ~SmallHeap() { delete hp; }

  Path *deleteTop() {
    if (rear == 0) {
      return NULL;
    }
    rear--;
    Path *top = hp[0];
    hp[0] = hp[rear];
    curidx = 0;
    while (true) {
      if (2 * curidx + 1 >= rear) {
        break;
      }
      if (2 * curidx + 2 >= rear) {
        min = 2 * curidx + 1;
      } else {
        min = hp[2 * curidx + 1]->time > hp[2 * curidx + 2]->time
                  ? (2 * curidx + 2)
                  : (2 * curidx + 1);
      }
      if (hp[curidx]->time > hp[min]->time) {
        temp = hp[curidx];
        hp[curidx] = hp[min];
        hp[min] = temp;
        curidx = min;
      } else {
        break;
      }
    }
    return top;
  }

  void insertHeap(Path *val) {
    curidx = rear;
    hp[rear++] = val;
    while (curidx > 0) {
      if (hp[curidx]->time < hp[(curidx - 1) / 2]->time) {
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  SmallHeap *sm = new SmallHeap(1000000);
  int *grp = new int[n * m];
  Path **minTime = new Path *[n * m];
  for (int i = 0; i < n * m; i++) {
    cin >> grp[i];
    minTime[i] = nil;
  }
  Path *topE;
  double tempVelo, tempTime;
  int tempIdx;
  sm->insertHeap(new Path{0, 0, 1});
  while (sm->rear != 0) {
    topE = sm->deleteTop();
    if (minTime[topE->idx] != nil && minTime[topE->idx]->time <= topE->time &&
        minTime[topE->idx]->velo >= topE->velo) {
      continue;
    } else {
      if (minTime[topE->idx] == nil || minTime[topE->idx]->time > topE->time) {
        minTime[topE->idx] = new Path{topE->idx, topE->time, topE->velo};
      }
      tempIdx = topE->idx;
      tempTime = topE->time + (1 / topE->velo);
      if (topE->idx % m != 0) {
        tempVelo = topE->velo * pow(2, (grp[tempIdx] - grp[tempIdx - 1]));
        sm->insertHeap(new Path{tempIdx - 1, tempTime, tempVelo});
      }
      if (topE->idx % m != m - 1) {
        tempVelo = topE->velo * pow(2, (grp[tempIdx] - grp[tempIdx + 1]));
        sm->insertHeap(new Path{tempIdx + 1, tempTime, tempVelo});
      }
      if (topE->idx / m != 0) {
        tempVelo = topE->velo * pow(2, (grp[tempIdx] - grp[tempIdx - m]));
        sm->insertHeap(new Path{tempIdx - m, tempTime, tempVelo});
      }
      if (topE->idx / m != n - 1) {
        tempVelo = topE->velo * pow(2, (grp[tempIdx] - grp[tempIdx + m]));
        sm->insertHeap(new Path{tempIdx + m, tempTime, tempVelo});
      }
    }
  }
  cout.setf(ios_base::fixed, ios_base::floatfield);
  cout.precision(2);
  cout << minTime[m * n - 1]->time;
  return 0;
}