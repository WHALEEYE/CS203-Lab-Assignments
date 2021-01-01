#include <iostream>
using namespace std;

struct Node {
  int value;
  Node *next;
  Node *pre;
};

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q, order, u, v, w, val;
  Node *temp, *cur1, *cur2;
  while (cin >> n) {
    cin >> q;
    Node *dqs[n];
    for (int i = 0; i < n; i++) {
      temp = new Node{-1, NULL, NULL};
      temp->pre = temp->next = temp;
      dqs[i] = temp;
    }
    for (int i = 0; i < q; i++) {
      cin >> order;
      switch (order) {
        case 1:
          cin >> u >> w >> val;
          if (w == 0) {
            temp = new Node{val, dqs[u - 1]->next, dqs[u - 1]};
            dqs[u - 1]->next->pre = temp;
            dqs[u - 1]->next = temp;
          } else {
            temp = new Node{val, dqs[u - 1], dqs[u - 1]->pre};
            dqs[u - 1]->pre->next = temp;
            dqs[u - 1]->pre = temp;
          }
          break;
        case 2:
          cin >> u >> w;
          if (w == 0) {
            cur1 = dqs[u - 1]->next;
            cout << cur1->value << "\n";
            cur1->pre->next = cur1->next;
            cur1->next->pre = cur1->pre;
          } else {
            cur1 = dqs[u - 1]->pre;
            cout << cur1->value << "\n";
            cur1->pre->next = cur1->next;
            cur1->next->pre = cur1->pre;
          }
          break;
        case 3:
          cin >> u >> v >> w;
          if (w == 0) {
            cur1 = dqs[v - 1]->next;
            cur2 = cur1->next;
            while (cur1 != dqs[v - 1]) {
              cur1->pre->next = cur1->next;
              cur1->next->pre = cur1->pre;
              cur1->pre = dqs[u - 1]->pre;
              cur1->next = dqs[u - 1];
              dqs[u - 1]->pre->next = cur1;
              dqs[u - 1]->pre = cur1;
              cur1 = cur2;
              cur2 = cur2->next;
            }
          } else {
            cur1 = dqs[v - 1]->pre;
            cur2 = cur1->pre;
            while (cur1 != dqs[v - 1]) {
              cur1->pre->next = cur1->next;
              cur1->next->pre = cur1->pre;
              cur1->pre = dqs[u - 1]->pre;
              cur1->next = dqs[u - 1];
              dqs[u - 1]->pre->next = cur1;
              dqs[u - 1]->pre = cur1;
              cur1 = cur2;
              cur2 = cur2->pre;
            }
          }
          break;
      }
    }
  }
  return 0;
}
