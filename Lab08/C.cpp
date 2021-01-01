#include <iostream>
using namespace std;
void quickSort(int seq[], int index[], int l, int r);
int pivot;
int idx, i, j;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, time, rear = 0;
    cin >> n;
    int pow[n], hour[n], hp[n];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> pow[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> hour[i];
    }
    quickSort(hour, pow, 0, n - 1);
    int j = 0, cur = 0, temp, min;
    time = hour[j];
    while (j < n) {
      time = hour[j];
      while (j < n && hour[j] == time) {
        hp[rear] = pow[j++];
        cur = rear;
        while (cur > 0) {
          if (hp[cur] < hp[(cur - 1) / 2]) {
            temp = hp[cur];
            hp[cur] = hp[(cur - 1) / 2];
            hp[(cur - 1) / 2] = temp;
            cur = (cur - 1) / 2;
          } else {
            break;
          }
        }
        rear++;
      }
      while (rear > time) {
        rear--;
        hp[0] = hp[rear];
        cur = 0;
        while (true) {
          if (2 * cur + 2 >= rear) {
            min = 2 * cur + 1;
          } else {
            min = hp[2 * cur + 1] > hp[2 * cur + 2] ? (2 * cur + 2)
                                                    : (2 * cur + 1);
          }
          if (hp[cur] > hp[min]) {
            temp = hp[cur];
            hp[cur] = hp[min];
            hp[min] = temp;
            cur = min;
          } else {
            break;
          }
          if (2 * cur + 1 >= rear) {
            break;
          }
        }
      }
    }
    for (int i = 0; i < rear; i++) {
      sum += (long long)hp[i];
    }
    cout << sum << '\n';
  }
  return 0;
}

void quickSort(int seq[], int index[], int l, int r) {
  if (l < r) {
    i = l;
    j = r;
    pivot = seq[l];
    idx = index[l];
    while (i < j) {
      while (i < j && seq[j] >= pivot) {
        j--;
      }
      if (i < j) {
        seq[i] = seq[j];
        index[i++] = index[j];
      }
      while (i < j && seq[i] < pivot) {
        i++;
      }
      if (i < j) {
        seq[j] = seq[i];
        index[j--] = index[i];
      }
    }
    index[i] = idx;
    seq[i] = pivot;
    quickSort(seq, index, l, i - 1);
    quickSort(seq, index, i + 1, r);
  }
}