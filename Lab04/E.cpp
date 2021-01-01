#include <iostream>
using namespace std;

struct Node {
  int value;
  bool deleted;
  Node *next;
  Node *pre;
};

int main() {
  int t;
  Node *head, *tail, *cur, *temp;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    head = new Node{-1, false, NULL, NULL};
    tail = head;
    int n, ins, d = 0, pnum = 0;
    Node *sted[50000][2], *cpoints[50000];
    bool cont = false;
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
      scanf("%d", &ins);
      temp = new Node{ins, false, NULL, tail};
      tail->next = temp;
      tail = temp;
    }
    tail->next = head;
    head->pre = tail;
    cur = head->next;
    while (true) {
      if (cur != head->pre &&
          (cur->pre->value > cur->value || cur->next->value < cur->value)) {
        sted[d][0] = cur;
        cur->deleted = true;
        while (true) {
          cur = cur->next;
          if (cur != head->pre &&
              (cur->pre->value > cur->value || cur->next->value < cur->value)) {
            continue;
          } else if (cur == head->pre && cur->pre->value > cur->value) {
            sted[d][1] = cur;
            cur->deleted = true;
            d++;
            break;
          } else {
            sted[d][1] = cur->pre;
            cur->pre->deleted = true;
            d++;
            break;
          }
        }
      }
      if (cur == head->pre) {
        break;
      }
      cur = cur->next;
    }
    for (int i = 0; i < d; i++) {
      if (sted[i][0] == head->next) {
        continue;
      } else {
        if (sted[i][0]->pre->deleted) {
          continue;
        } else {
          cpoints[pnum] = sted[i][0]->pre;
          pnum++;
        }
      }
    }
    for (int i = 0; i < d; i++) {
      sted[i][0]->pre->next = sted[i][1]->next;
      sted[i][1]->next->pre = sted[i][0]->pre;
    }
    do {
      d = 0;
      cont = false;
      for (int j = 0; j < pnum; j++) {
        cur = cpoints[j];
        if (cur != head->pre &&
            (cur->pre->value > cur->value || cur->next->value < cur->value)) {
          cont = true;
          sted[d][0] = cur;
          cur->deleted = true;
          while (true) {
            cur = cur->next;
            if (cur != head->pre && (cur->pre->value > cur->value ||
                                     cur->next->value < cur->value)) {
              if (j < pnum - 1 && cur == cpoints[j + 1]) {
                j++;
              }
              continue;
            } else if (cur == head->pre && cur->pre->value > cur->value) {
              if (j < pnum - 1 && cur == cpoints[j + 1]) {
                j++;
              }
              sted[d][1] = cur;
              cur->deleted = true;
              d++;
              break;
            } else {
              sted[d][1] = cur->pre;
              cur->pre->deleted = true;
              d++;
              break;
            }
          }
        }
      }
      pnum = 0;
      for (int i = 0; i < d; i++) {
        if (sted[i][0] == head->next) {
          continue;
        } else {
          if (sted[i][0]->pre->deleted) {
            continue;
          } else {
            cpoints[pnum] = sted[i][0]->pre;
            pnum++;
          }
        }
      }
      for (int i = 0; i < d; i++) {
        sted[i][0]->pre->next = sted[i][1]->next;
        sted[i][1]->next->pre = sted[i][0]->pre;
      }
    } while (cont);
    cur = head->next;
    while (cur != head) {
      printf("%d ", cur->value);
      cur = cur->next;
    }
    printf("\n");
  }
  return 0;
}