#include <iostream>
using namespace std;

int main() {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    int seq1[n], seq2[n], count1 = 0, count2 = 0, k, temp, tt;
    for (int i = 0; i < n; i++) {
      cin >> tt;
      seq2[i] = seq1[i] = tt;
    }
    for (int i = 0; i < n - 1; i++) {
      k = i;
      for (int j = i + 1; j < n; j++) {
        if (seq1[k] > seq1[j]) {
          k = j;
        }
        count1++;
      }
      temp = seq1[k];
      seq1[k] = seq1[i];
      seq1[i] = temp;
      count1++;
    }
    for (int i = 1; i < n; i++) {
      for (int j = i; j > 0; j--) {
        count2++;
        if (seq2[j] < seq2[j - 1]) {
          temp = seq2[j];
          seq2[j] = seq2[j - 1];
          seq2[j - 1] = temp;
          count2++;
        } else {
          break;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << seq1[i];
      if (i != n - 1) {
        cout << " ";
      }
    }
    cout << endl;
    cout << (count1 > count2 ? "Insertion" : "Selection") << " Sort wins!"
         << endl;
  }
  return 0;
}