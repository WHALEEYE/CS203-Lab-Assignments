#include <iostream>
using namespace std;
#include <cmath>
typedef long long ll;
int x, y, n;

ll move(ll t, char opr[], int dx, int dy) {
  ll cx = x, cy = y, cycle = t / n, extra = t % n;
  cx += dx * cycle;
  cy += dy * cycle;
  for (int i = 0; i < extra; i++) {
    switch (opr[i]) {
      case 'U':
        cx++;
        break;
      case 'L':
        cx--;
        break;
      case 'R':
        cy++;
        break;
      case 'D':
        cy--;
        break;
    }
  }
  return abs(cx) + abs(cy);
}

int main() {
  int temp, dx = 0, dy = 0;
  ll t = (ll)1e18, st = 0, mid;
  cin >> x >> y;
  cin >> temp;
  x -= temp;
  cin >> temp;
  y -= temp;
  cin >> n;
  char opr[n];
  for (int i = 0; i < n; i++) {
    cin >> opr[i];
    switch (opr[i]) {
      case 'U':
        dx++;
        break;
      case 'L':
        dx--;
        break;
      case 'R':
        dy++;
        break;
      case 'D':
        dy--;
        break;
    }
  }
  if (move(t, opr, dx, dy) > t) {
    cout << -1 << endl;
    return 0;
  }
  while (st < t) {
    mid = (st + t) / 2;
    if (move(mid, opr, dx, dy) > mid) {
      st = mid + 1;
    } else {
      t = mid;
    }
  }
  cout << t << endl;
  return 0;
}