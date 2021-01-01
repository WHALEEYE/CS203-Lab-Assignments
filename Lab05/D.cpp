#include <iostream>
using namespace std;

struct Node {
  int value;
  int pos;
};

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n, q, idx;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    int qunum, time[n], top = 0;
    Node *stack[n], *temp;
    for (int j = 0; j < n; j++) {
      cin >> idx;
      temp = new Node{idx, j};
      if (top == 0 || stack[top - 1]->value >= idx) {
        stack[top++] = temp;
      } else {
        while (top != 0 && stack[top - 1]->value < idx) {
          time[stack[top - 1]->pos] = j - stack[top - 1]->pos;
          if (top != 0) {
            delete stack[top - 1];
          }
          top--;
        }
        stack[top++] = temp;
      }
    }
    for (int j = 0; j < top; j++) {
      time[stack[j]->pos] = -1;
    }
    cin >> q;
    for (int j = 0; j < q; j++) {
      cin >> qunum;
      cout << time[qunum - 1] << "\n";
    }
  }
  return 0;
}