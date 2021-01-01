#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ull;
const int BASE = 257;

void table(ull power[], int lmax) {
  power[0] = 1;
  for (int i = 1; i < lmax; i++) {
    power[i] = power[i - 1] * BASE;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s1, s2, smin, smax;
  cin >> s1;
  cin >> s2;
  int l1 = s1.length(), l2 = s2.length();
  int lmin = min(l1, l2), lmax = max(l1, l2);
  int ed = lmin, k, st = 0, mid, l, r, mmid, lhash;
  bool find;
  ull hash1, hash2, *hash, power[lmax];
  table(power, lmax);
  smin = l1 > l2 ? s2 : s1;
  smax = l1 <= l2 ? s2 : s1;
  while (st < ed) {
    find = false;
    mid = (st + ed + 1) / 2;
    lhash = lmin - mid + 1;
    hash = new ull[lhash];
    hash1 = 0;
    hash2 = 0;
    k = 1;
    for (int i = 0; i < mid; i++) {
      hash1 *= BASE;
      hash1 += smin[i];
    }
    hash[0] = hash1;
    for (int i = mid; i < lmin; i++) {
      hash1 -= (smin[i - mid]) * power[mid - 1];
      hash1 *= BASE;
      hash1 += smin[i];
      hash[k] = hash1;
      k++;
    }
    sort(hash, hash + lhash);
    for (int i = 0; i < mid; i++) {
      hash2 *= BASE;
      hash2 += smax[i];
    }
    l = 0;
    r = lmin - mid;
    while (l <= r) {
      mmid = (l + r) / 2;
      if (hash[mmid] < hash2) {
        l = mmid + 1;
      } else if (hash[mmid] > hash2) {
        r = mmid - 1;
      } else {
        find = true;
        break;
      }
    }
    if (!find) {
      for (int i = mid; i < lmax; i++) {
        hash2 -= (smax[i - mid]) * power[mid - 1];
        hash2 *= BASE;
        hash2 += smax[i];
        l = 0;
        r = lhash - 1;
        while (l <= r) {
          mmid = (l + r) / 2;
          if (hash[mmid] < hash2) {
            l = mmid + 1;
          } else if (hash[mmid] > hash2) {
            r = mmid - 1;
          } else {
            find = true;
            break;
          }
        }
      }
    }
    if (find) {
      st = mid;
    } else {
      ed = mid - 1;
    }
  }
  cout << ed << endl;
  return 0;
}
