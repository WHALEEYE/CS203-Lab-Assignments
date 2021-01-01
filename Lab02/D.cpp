#include <iostream>
using namespace std;
int split(int ipt[], int n, int x);

int main() {
  int n, m, st = 0, ed = 1000000000, mid;
  cin >> n >> m;
  int ipt[n + 1], pcs[n];
  cin >> ipt[n];
  for (int i = 0; i < n; i++) {
    cin >> ipt[i];
  }
  for (int i = 0; i < n; i++) {
    pcs[i] = ipt[i + 1] - ipt[i];
  }
  while (st < ed) {
    mid = (st + ed) / 2;
    if (split(pcs, n, mid) <= m) {
      ed = mid;
    } else {
      st = mid + 1;
    }
  }
  cout << ed << endl;
}

int split(int ipt[], int n, int x) {
  int num = 1, sum = 0;
  for (int i = 0; i < n; i++) {
    sum += ipt[i];
    if (sum > x) {
      num++;
      sum = ipt[i];
    }
  }
  return num;
}
