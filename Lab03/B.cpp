#include <iostream>
using namespace std;
int quickSort(int seq[], int tseq[], int l, int r);
int ll, rr, pivot, n, k, p;

int main() {
  scanf("%d%d", &n, &k);
  int seq[n], tseq[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &seq[i]);
  }
  printf("%d\n", quickSort(seq, tseq, 0, n - 1));
  return 0;
}

int quickSort(int seq[], int tseq[], int l, int r) {
  ll = l;
  rr = r;
  pivot = seq[r];
  for (int i = l; i < r; i++) {
    if (seq[i] < pivot) {
      tseq[ll++] = seq[i];
    } else {
      tseq[rr--] = seq[i];
    }
  }
  tseq[ll] = pivot;
  if (ll - l + 1 == k) {
    return pivot;
  } else if (ll - l + 1 < k) {
    k = k - ll + l - 1;
    return quickSort(tseq, seq, ll + 1, r);
  } else {
    return quickSort(tseq, seq, l, ll - 1);
  }
}