#include <iostream>
using namespace std;

int main() {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    int ipt[n], mns[n - 1];
    for (int j = 0; j < n; j++) {
      cin >> ipt[j];
      if (j == 0) {
        continue;
      }
      mns[j - 1] = ipt[j - 1] - ipt[j];
    }
    int max, fm;
    max = fm = mns[0];
    for (int j = 1; j < n - 1; j++) {
      fm = (fm > 0 ? (fm + mns[j]) : mns[j]);
      max = (max > fm ? max : fm);
    }
    cout << max << endl;
  }
  return 0;
}