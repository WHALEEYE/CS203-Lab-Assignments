#include <iostream>
typedef long long ll;
ll pivot;
int i, j;
using namespace std;

void quickSort(ll seq[], int l, int r) {
  if (l < r) {
    i = l;
    j = r;
    pivot = seq[l];
    while (i < j) {
      while (i < j && seq[j] >= pivot) {
        j--;
      }
      if (i < j) {
        seq[i] = seq[j];
      }
      while (i < j && seq[i] < pivot) {
        i++;
      }
      if (i < j) {
        seq[j] = seq[i];
      }
    }
    seq[i] = pivot;
    quickSort(seq, l, i - 1);
    quickSort(seq, i + 1, r);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, sum = 0, sub = 0, l, r, mid;
    cin >> n;
    ll ipt[n];
    for (int i = 0; i < n; i++) {
      cin >> ipt[i];
    }
    if (n == 1) {
      cout << 0 << "\n";
      continue;
    }
    quickSort(ipt, 0, n - 1);
    for (int i = 1; i < n; i++) {
      sub = ipt[i - 1] + ipt[i];
      sum += sub;
      ipt[i] = sub;
      int j = i;
      ll temp;
      while (j < n - 1 && ipt[j] > ipt[j + 1]) {
        temp = ipt[j + 1];
        ipt[j + 1] = ipt[j];
        ipt[j] = temp;
        j++;
      }
    }
    cout << sum << "\n";
  }
  return 0;
}
