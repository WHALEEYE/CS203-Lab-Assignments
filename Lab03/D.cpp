#include <iostream>
using namespace std;
void mergeSort(int seq[], int tseq[], int l, int r);
void combine(int seq[], int tseq[], int l, int mid, int r);
int mid, s, k, p;
long long count;

int main() {
  int t, n;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    count = 0;
    int seq[n], tseq[n], tt;
    for (int j = 0; j < n; j++) {
      scanf("%d", &tt);
      seq[j] = tseq[j] = tt;
    }
    mergeSort(seq, tseq, 0, n - 1);
    printf("%lld\n", count);
  }
  return 0;
}

void mergeSort(int seq[], int tseq[], int l, int r) {
  if (l < r) {
    mid = (l + r) / 2;
    mergeSort(seq, tseq, l, mid);
    mid = (l + r) / 2;
    mergeSort(seq, tseq, mid + 1, r);
    mid = (l + r) / 2;
    combine(seq, tseq, l, mid, r);
  }
}

void combine(int seq[], int tseq[], int l, int mid, int r) {
  s = l, k = mid + 1, p = l;
  while (true) {
    if (s <= mid && k <= r) {
      if (seq[s] > seq[k]) {
        tseq[p] = seq[k];
        k++;
        count += (mid - s + 1);
      } else {
        tseq[p] = seq[s];
        s++;
      }
    } else if (s == mid + 1) {
      tseq[p] = seq[k];
      k++;
    } else if (k == r + 1) {
      tseq[p] = seq[s];
      s++;
    }
    if (s == mid + 1 && k == r + 1) {
      for (int i = l; i <= r; i++) {
        seq[i] = tseq[i];
      }
      break;
    }
    p++;
  }
}
