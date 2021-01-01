#include <iostream>
using namespace std;

template <class K>
struct bstNode {
  K value;
  int bf;
  long long num;
  bstNode<K> *parent;
  bstNode<K> *leftC;
  bstNode<K> *rightC;
};

template <class K>
class AVLTree {
 private:
  bool taller, lower;
  bstNode<K> *p;

 public:
  bstNode<K> *root;

  AVLTree(K rootval) {
    this->root = new bstNode<K>{rootval, 0, 1, NULL, NULL, NULL};
  }

  void reNum(bstNode<K> *T) {
    if (T->leftC != NULL && T->rightC != NULL) {
      T->num = T->leftC->num + T->rightC->num + 1;
    } else if (T->leftC != NULL) {
      T->num = T->leftC->num + 1;
    } else if (T->rightC != NULL) {
      T->num = T->rightC->num + 1;
    } else {
      T->num = 1;
    }
  }

  void leftRot(bstNode<K> *T) {
    bstNode<K> *R = T->rightC;
    if (R->leftC != NULL) {
      R->leftC->parent = T;
    }
    T->rightC = R->leftC;
    if (T->parent != NULL) {
      if (T->parent->leftC == T) {
        T->parent->leftC = R;
      } else {
        T->parent->rightC = R;
      }
    }
    R->parent = T->parent;
    T->parent = R;
    R->leftC = T;
    reNum(T);
    reNum(R);
    if (T == root) {
      root = R;
    }
  }

  void rightRot(bstNode<K> *T) {
    bstNode<K> *L = T->leftC;
    if (L->rightC != NULL) {
      L->rightC->parent = T;
    }
    T->leftC = L->rightC;
    if (T->parent != NULL) {
      if (T->parent->leftC == T) {
        T->parent->leftC = L;
      } else {
        T->parent->rightC = L;
      }
    }
    L->parent = T->parent;
    T->parent = L;
    L->rightC = T;
    reNum(T);
    reNum(L);
    if (T == root) {
      root = L;
    }
  }

  bstNode<K> *leftHigh(bstNode<K> *T) {
    bstNode<K> *L, *Lr;
    L = T->leftC;
    Lr = L->rightC;
    switch (L->bf) {
      case 1:
        L->bf = T->bf = 0;
        rightRot(T);
        return L;
        break;
      case -1:
        switch (Lr->bf) {
          case 1:
            L->bf = 0;
            T->bf = -1;
            break;
          case 0:
            L->bf = T->bf = 0;
            break;
          case -1:
            L->bf = 1;
            T->bf = 0;
            break;
        }
        Lr->bf = 0;
        leftRot(L);
        rightRot(T);
        return Lr;
        break;
      case 0:
        L->bf = -1;
        T->bf = 1;
        rightRot(T);
        return L;
        break;
    }
  }

  bstNode<K> *rightHigh(bstNode<K> *T) {
    bstNode<K> *R, *Rl;
    R = T->rightC;
    Rl = R->leftC;
    switch (R->bf) {
      case -1:
        R->bf = T->bf = 0;
        leftRot(T);
        return R;
        break;
      case 1:
        switch (Rl->bf) {
          case 1:
            R->bf = -1;
            T->bf = 0;
            break;
          case 0:
            R->bf = T->bf = 0;
            break;
          case -1:
            R->bf = 0;
            T->bf = 1;
            break;
        }
        Rl->bf = 0;
        rightRot(R);
        leftRot(T);
        return Rl;
        break;
      case 0:
        R->bf = 1;
        T->bf = -1;
        leftRot(T);
        return R;
        break;
    }
  }

  bstNode<K> *findSuc(bstNode<K> *T, K q) {
    if (T == NULL) {
      return p;
    } else if (q == T->value) {
      return T;
    } else if (q < T->value) {
      p = T;
      return findSuc(T->leftC, q);
    } else {
      return findSuc(T->rightC, q);
    }
  }

  bstNode<K> *findPred(bstNode<K> *T, K q) {
    if (T == NULL) {
      return p;
    } else if (q == T->value) {
      return T;
    } else if (q < T->value) {
      return findPred(T->leftC, q);
    } else {
      p = T;
      return findPred(T->rightC, q);
    }
  }

  void treeInsert(K val) {
    bstNode<K> *T = root, *cld, *cur;
    while (true) {
      if (val == T->value) {
        return;
      } else if (val < T->value) {
        if (T->leftC == NULL) {
          break;
        }
        T = T->leftC;
      } else {
        if (T->rightC == NULL) {
          break;
        }
        T = T->rightC;
      }
    }
    if (val < T->value) {
      T->leftC = new bstNode<K>{val, 0, 1, T, NULL, NULL};
      cur = T;
      while (cur != NULL) {
        cur->num++;
        cur = cur->parent;
      }
      switch (T->bf) {
        case -1:
          T->bf = 0;
          taller = false;
          break;
        case 0:
          T->bf = 1;
          taller = true;
          break;
      }
    } else {
      T->rightC = new bstNode<K>{val, 0, 1, T, NULL, NULL};
      cur = T;
      while (cur != NULL) {
        cur->num++;
        cur = cur->parent;
      }
      switch (T->bf) {
        case 1:
          T->bf = 0;
          taller = false;
          break;
        case 0:
          T->bf = -1;
          taller = true;
          break;
      }
    }
    while (T != root) {
      cld = T;
      T = T->parent;
      if (T->leftC == cld) {
        if (taller) {
          switch (T->bf) {
            case -1:
              T->bf = 0;
              taller = false;
              break;
            case 0:
              T->bf = 1;
              taller = true;
              break;
            case 1:
              T = leftHigh(T);
              taller = false;
              break;
          }
        }
      } else {
        if (taller) {
          switch (T->bf) {
            case -1:
              T = rightHigh(T);
              taller = false;
              break;
            case 0:
              T->bf = -1;
              taller = true;
              break;
            case 1:
              T->bf = 0;
              taller = false;
              break;
          }
        }
      }
    }
  }

  void treeDelete(K val) {
    bstNode<K> *T, *temp, *U, *cur;
    T = root;
    while (val != T->value) {
      if (val < T->value) {
        T = T->leftC;
      } else {
        T = T->rightC;
      }
    }
    if (T->leftC == NULL && T->rightC == NULL) {
      temp = T;
      T = T->parent;
      if (T == NULL) {
        root = NULL;
        delete temp;
        return;
      }
      if (T->leftC == temp) {
        T->leftC = NULL;
        cur = T;
        while (cur != NULL) {
          cur->num--;
          cur = cur->parent;
        }
        switch (T->bf) {
          case -1:
            lower = (T->rightC->bf == 0) ? false : true;
            T = rightHigh(T);
            break;
          case 0:
            T->bf = -1;
            lower = false;
            break;
          case 1:
            T->bf = 0;
            lower = true;
            break;
        }
      } else {
        T->rightC = NULL;
        cur = T;
        while (cur != NULL) {
          cur->num--;
          cur = cur->parent;
        }
        switch (T->bf) {
          case -1:
            T->bf = 0;
            lower = true;
            break;
          case 0:
            T->bf = 1;
            lower = false;
            break;
          case 1:
            lower = (T->leftC->bf == 0) ? false : true;
            T = leftHigh(T);
            break;
        }
      }
      delete temp;
      reBalDel(T, lower);
    } else if (T->rightC == NULL) {
      bstNode<K> *temp2;
      temp2 = T->leftC;
      temp = T;
      T = T->parent;
      temp2->parent = T;
      if (T == NULL) {
        root = temp2;
        delete temp;
        return;
      }
      if (T->leftC == temp) {
        T->leftC = temp2;
      } else {
        T->rightC = temp2;
      }
      cur = T;
      while (cur != NULL) {
        cur->num--;
        cur = cur->parent;
      }
      delete temp;
      reBalDel(temp2, true);
    } else {
      U = findSuc(T->rightC, T->value);
      T->value = U->value;
      if (U->rightC == NULL) {
        temp = U;
        U = U->parent;
        if (U->leftC == temp) {
          U->leftC = NULL;
          cur = U;
          while (cur != NULL) {
            cur->num--;
            cur = cur->parent;
          }
          switch (U->bf) {
            case -1:
              lower = (U->rightC->bf == 0) ? false : true;
              U = rightHigh(U);
              break;
            case 0:
              U->bf = -1;
              lower = false;
              break;
            case 1:
              U->bf = 0;
              lower = true;
              break;
          }
        } else {
          U->rightC = NULL;
          cur = U;
          while (cur != NULL) {
            cur->num--;
            cur = cur->parent;
          }
          switch (U->bf) {
            case -1:
              U->bf = 0;
              lower = true;
              break;
            case 0:
              U->bf = 1;
              lower = false;
              break;
            case 1:
              lower = (U->leftC->bf == 0) ? false : true;
              U = leftHigh(U);
              break;
          }
        }
        delete temp;
        reBalDel(U, lower);
      } else {
        bstNode<K> *temp2;
        temp2 = U->rightC;
        temp = U;
        U = U->parent;
        temp2->parent = U;
        if (U->leftC == temp) {
          U->leftC = temp2;
        } else {
          U->rightC = temp2;
        }
        cur = U;
        while (cur != NULL) {
          cur->num--;
          cur = cur->parent;
        }
        delete temp;
        reBalDel(temp2, true);
      }
    }
  }

  void reBalDel(bstNode<K> *T, bool lower) {
    bstNode<K> *cld;
    cld = T;
    T = T->parent;
    while (T != NULL) {
      if (T->leftC == cld) {
        if (lower) {
          switch (T->bf) {
            case -1:
              lower = (T->rightC->bf == 0) ? false : true;
              T = rightHigh(T);
              break;
            case 0:
              T->bf = -1;
              lower = false;
              break;
            case 1:
              T->bf = 0;
              lower = true;
              break;
          }
        }
      } else {
        if (lower) {
          switch (T->bf) {
            case -1:
              T->bf = 0;
              lower = true;
              break;
            case 0:
              T->bf = 1;
              lower = false;
              break;
            case 1:
              lower = (T->leftC->bf == 0) ? false : true;
              T = leftHigh(T);
              break;
          }
        }
      }
      cld = T;
      T = T->parent;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int m, k;
  cin >> m >> k;
  int val, seq[m], order[m - k + 1], th;
  for (int i = 0; i < m; i++) {
    cin >> seq[i];
  }
  for (int i = 0; i < m - k + 1; i++) {
    cin >> order[i];
  }
  AVLTree<int> *a = new AVLTree<int>(seq[0]);
  for (int i = 1; i < k; i++) {
    a->treeInsert(seq[i]);
  }
  th = order[0];
  bstNode<int> *T = a->root;
  while (true) {
    if (T->num == 1) {
      cout << T->value << '\n';
      break;
    }
    if (T->leftC == NULL) {
      if (th == 1) {
        cout << T->value << '\n';
        break;
      } else {
        th -= 1;
        T = T->rightC;
      }
    } else if ((T->leftC->num + 1) == th) {
      cout << T->value << '\n';
      break;
    } else if ((T->leftC->num + 1) < th) {
      th = th - T->leftC->num - 1;
      T = T->rightC;
    } else {
      T = T->leftC;
    }
  }

  for (int i = k; i < m; i++) {
    th = order[i - k + 1];
    a->treeInsert(seq[i]);
    a->treeDelete(seq[i - k]);
    T = a->root;
    while (true) {
      if (T->num == 1) {
        cout << T->value << '\n';
        break;
      }
      if (T->leftC == NULL) {
        if (th == 1) {
          cout << T->value << '\n';
          break;
        } else {
          th -= 1;
          T = T->rightC;
        }
      } else if ((T->leftC->num + 1) == th) {
        cout << T->value << '\n';
        break;
      } else if ((T->leftC->num + 1) < th) {
        th = th - T->leftC->num - 1;
        T = T->rightC;
      } else {
        T = T->leftC;
      }
    }
  }
  return 0;
}