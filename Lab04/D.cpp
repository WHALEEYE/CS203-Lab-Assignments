#include <iostream>
using namespace std;
void mergeSort(int seq[], int tseq[], int idx[], int tidx[], int l, int r);
void combine(int seq[], int tseq[], int idx[], int tidx[], int l, int mid,
             int r);
int mid, s, k, p;

struct Node {
  int value;
  int idx;
  Node *next;
  Node *pre;
};

int main() {
  int t;
  scanf("%d", &t);
  Node *head, *tail, *cur, *temp;
  for (int i = 0; i < t; i++) {
    head = new Node{-1, -1, head, head};
    tail = head;
    bool dela = false;
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) {
      dela = true;
      n--;
    }
    int vle, v[n], tv[n], idx[n], tidx[n], rst[(n + 1) / 2], i1, i2, lmid;
    Node *add[n];
    for (int j = 0; j < n; j++) {
      scanf("%d", &vle);
      v[j] = vle;
      idx[j] = j;
    }
    if (dela) {
      scanf("%d", &vle);
    }
    mergeSort(v, tv, idx, tidx, 0, n - 1);
    for (int j = 0; j < n; j++) {
      tidx[idx[j]] = j;
    }
    for (int j = 0; j < n; j++) {
      temp = new Node{v[j], j, head, tail};
      add[j] = temp;
      tail->next = temp;
      tail = temp;
    }
    lmid = n / 2;
    cur = add[lmid];
    for (int j = 0; j < (n + 1) / 2; j++) {
      rst[(n + 1) / 2 - 1 - j] = cur->value;
      if (j == (n + 1) / 2 - 1) {
        break;
      }
      i1 = tidx[n - 1 - 2 * j];
      i2 = tidx[n - 2 - 2 * j];
      if (i1 <= lmid && i2 <= lmid) {
        cur = cur->next;
      } else if (i1 >= lmid && i2 >= lmid) {
        cur = cur->pre;
      }
      add[i1]->pre->next = add[i1]->next;
      add[i1]->next->pre = add[i1]->pre;
      delete add[i1];
      add[i2]->pre->next = add[i2]->next;
      add[i2]->next->pre = add[i2]->pre;
      delete add[i2];
      lmid = cur->idx;
    }
    for (int j = 0; j < (n + 1) / 2; j++) {
      printf("%d ", rst[j]);
    }
    printf("\n");
  }
  return 0;
}

void mergeSort(int seq[], int tseq[], int idx[], int tidx[], int l, int r) {
  if (l < r) {
    mid = (l + r) / 2;
    mergeSort(seq, tseq, idx, tidx, l, mid);
    mid = (l + r) / 2;
    mergeSort(seq, tseq, idx, tidx, mid + 1, r);
    mid = (l + r) / 2;
    combine(seq, tseq, idx, tidx, l, mid, r);
  }
}

void combine(int seq[], int tseq[], int idx[], int tidx[], int l, int mid,
             int r) {
  s = l, k = mid + 1, p = l;
  while (true) {
    if (s <= mid && k <= r) {
      if (seq[s] > seq[k]) {
        tseq[p] = seq[k];
        tidx[p] = idx[k];
        k++;
      } else {
        tseq[p] = seq[s];
        tidx[p] = idx[s];
        s++;
      }
    } else if (s == mid + 1) {
      tseq[p] = seq[k];
      tidx[p] = idx[k];
      k++;
    } else if (k == r + 1) {
      tseq[p] = seq[s];
      tidx[p] = idx[s];
      s++;
    }
    if (s == mid + 1 && k == r + 1) {
      for (int i = l; i <= r; i++) {
        seq[i] = tseq[i];
        idx[i] = tidx[i];
      }
      break;
    }
    p++;
  }
}