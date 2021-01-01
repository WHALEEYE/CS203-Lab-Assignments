#include <iostream>
using namespace std;

template <class K>
struct bstNode {
  K value;
  int bf;  //平衡因子，值为该节点左子树高度减右子树高度
  bstNode<K> *parent;
  bstNode<K> *leftC;
  bstNode<K> *rightC;
};

template <class K>
class AVLTree {
 private:
  bool taller, lower;

 public:
  bstNode<K> *root;

  AVLTree(K rootval) {
    this->root = new bstNode<K>{rootval, 0, NULL, NULL, NULL};
  }

  //左旋转
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
    if (T == root) {
      root = R;
    }
  }

  //右旋转
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
    if (T == root) {
      root = L;
    }
  }

  // T的左边高，不平衡，使其平衡，右旋转，右旋转前先检查L->bf，
  //如果为RH，L要先进行左旋转，使T->leftC->bf和T->bf一致
  //返回平衡后的顶点
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

  // T的右边高，不平衡，使其平衡，左旋转，左旋转前先检查R->bf,
  //如果为LH，R要先进行右旋转，使T->rightC->bf和T->bf一致
  //返回平衡后的顶点
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

  //给定一个值q，寻找以T节点为根的子树中该值的Successor
  bstNode<K> *findSuc(bstNode<K> *T, bstNode<K> *p， K q) {
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

  //给定一个值q，寻找以T节点为根的子树中该值的Predecessor
  bstNode<K> *findPred(bstNode<K> *T, bstNode<K> *p， K q) {
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
      T->leftC = new bstNode<K>{val, 0, T, NULL, NULL};
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
      T->rightC = new bstNode<K>{val, 0, T, NULL, NULL};
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
    bstNode<K> *T, *temp, *U;
    T = root;
    while (val != T->value) {
      if (val < T->value) {
        T = T->leftC;
      } else {
        T = T->rightC;
      }
    }
    if (T->leftC == NULL && T->rightC == NULL)  // T本身为叶子节点 直接删除T即可
    {
      temp = T;
      T = T->parent;
      if (T == NULL)  // T为根的情况
      {
        root = NULL;
        delete temp;
        return;
      }
      if (T->leftC == temp) {
        T->leftC = NULL;
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
    } else if (
        T->rightC ==
        NULL)  // T无右子树，直接用左节点（因为平衡，所以左子树只有一个节点）替换
    {
      bstNode<K> *temp2;
      temp2 = T->leftC;
      temp = T;
      T = T->parent;
      temp2->parent = T;
      if (T == NULL)  // T为根的情况
      {
        root = temp2;
        delete temp;
        return;
      }
      if (T->leftC == temp) {
        T->leftC = temp2;
      } else {
        T->rightC = temp2;
      }
      delete temp;
      reBalDel(temp2, true);
    } else  //又有左子树又有右子树，需要先找到successor
    {
      U = findSuc(T->rightC, T->rightC, T->value);
      T->value = U->value;  //将T用U替换，这里表示为value的替换
      if (U->rightC ==
          NULL)  // U无右子树，即U为叶子节点（Successor不可能有左子树）
      {
        temp = U;
        U = U->parent;
        if (U->leftC == temp) {
          U->leftC = NULL;
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
      } else  // U有右节点，此时需要将U用右节点替换
      {
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