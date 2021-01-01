#include <iostream>
using namespace std;

int main() {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    int ipt[n], tot = 0, ways = 0;
    for (int j = 0; j < n; j++) {
      cin >> ipt[j];
      tot ^= ipt[j];
    }
    for (int j = 0; j < n; j++) {
      if (ipt[j] > (tot ^ ipt[j])) {
        ways += 1;
      }
    }
    cout << ways << endl;
  }
  return 0;
}