#include <iostream>
using namespace std;

struct Node {
  int idx;
  Node *next;
};

int main() {
  int t, n, k;
  Node *head, *tail, *temp, *now1, *now2;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    tail = new Node{1, NULL};
    head = new Node{0, tail};
    scanf("%d%d", &n, &k);
    for (int j = 2; j <= n; j++) {
      temp = new Node{j, NULL};
      tail->next = temp;
      tail = temp;
    }
    tail->next = head;
    now1 = head->next;
    now2 = head;
    while (true) {
      for (int ii = 0; ii < k - 1; ii++) {
        now1 = now1->next;
        now2 = now2->next;
        if (now1 == head) {
          now1 = now1->next;
          now2 = now2->next;
        }
      }
      printf("%d ", now1->idx);
      now2->next = now1->next;
      now1 = now1->next;
      if (now1 == head) {
        now1 = now1->next;
        now2 = now2->next;
      }
      if (head->next == head) {
        break;
      }
    }
    printf("\n");
  }
  return 0;
}