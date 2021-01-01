#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n, ini, pwi, h;
  cin >> t;
  for (int i = 0; i < t; i++) {
    h = 1;
    pwi = 2;
    cin >> n;
    while (pwi <= n) {
      pwi *= 2;
      h++;
    }
    cout << h << endl;
  }
  return 0;
}