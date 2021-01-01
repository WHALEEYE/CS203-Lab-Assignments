#include <iostream>
using namespace std;

struct Node {
  char con;
  Node *next;
  Node *pre;
};

int main() {
  int t;
  Node *head, *tail, *temp, *cur;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n, order, slgh = 0, d = 1, pos, divpos, iptpos = 0;
    char ipt[200001];
    Node *hash[200];
    head = new Node{'\0', NULL, NULL};
    head->next = head->pre = head;
    tail = head;
    hash[0] = head;
    char ch, insertedc;
    scanf("%s", &ipt);
    while (true) {
      ch = ipt[iptpos];
      if (ch == '\0') {
        break;
      }
      temp = new Node{ch, head, tail};
      tail->next = temp;
      tail = temp;
      slgh++;
      if (slgh % 2000 == 0) {
        hash[d] = temp;
        d++;
      }
      iptpos++;
    }
    head->pre = tail;
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
      scanf("%d ", &order);
      switch (order) {
        case 1:
          scanf("%c%d", &insertedc, &pos);
          divpos = (pos / 2000) < (d - 1) ? (pos / 2000) : (d - 1);
          cur = hash[divpos];
          for (int k = 2000 * divpos; k < pos; k++) {
            cur = cur->next;
          }
          temp = new Node{insertedc, cur, cur->pre};
          if (pos == divpos * 2000) {
            hash[divpos] = temp;
          }
          cur->pre->next = temp;
          cur->pre = temp;
          for (int k = divpos + 1; k < d; k++) {
            hash[k] = hash[k]->pre;
          }
          slgh++;
          if (slgh / 2000 >= d) {
            hash[d] = head->pre;
            d++;
          }
          break;
        case 2:
          scanf("%d", &pos);
          divpos = pos / 2000;
          cur = hash[divpos];
          for (int k = 2000 * divpos; k < pos; k++) {
            cur = cur->next;
          }
          printf("%c\n", cur->con);
          break;
      }
    }
  }
  return 0;
}