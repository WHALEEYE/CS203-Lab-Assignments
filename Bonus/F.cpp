#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  priority_queue<long long> pq;
  int n, o;
  long long k;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> o >> k;
    if (o == 1) {
      pq.push(k);
    } else if (o == 2) {
      for (int j = 1; j < k; j++) {
        pq.pop();
      }
      cout << pq.top() << '\n';
    }
  }
  return 0;
}