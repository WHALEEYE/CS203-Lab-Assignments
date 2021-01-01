#include <iostream>
using namespace std;

int main() {
  int t, n, m;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> m;
    int a1[n], a2[m];
    for (int j = 0; j < n; j++) {
      cin >> a1[j];
    }
    for (int j = 0; j < m; j++) {
      cin >> a2[j];
    }
    int s = 0, k = 0;
    while (true) {
      if (s < n && k < m) {
        if (a1[s] > a2[k]) {
          cout << a2[k];
          k++;
        } else {
          cout << a1[s];
          s++;
        }
      } else if (s == n) {
        cout << a2[k];
        k++;
      } else if (k == m) {
        cout << a1[s];
        s++;
      }
      if (s == n && k == m) {
        cout << endl;
        break;
      }
      cout << " ";
    }
  }
  return 0;
}