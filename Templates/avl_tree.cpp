#include <iostream>
using namespace std;

struct bstNode
{
    int value;
    int bf; //平衡因子，值为该节点左子树高度减右子树高度
    bstNode *parent;
    bstNode *leftC;
    bstNode *rightC;
};

//左旋转
void leftRot(bstNode *T)
{
    bstNode *R = T->rightC;
    T->rightC = R->leftC;
    R->leftC = T;
}

//右旋转
void rightRot(bstNode *T)
{
    bstNode *L = T->leftC;
    T->leftC = L->rightC;
    L->rightC = T;
    return;
}

//T 的左边高，不平衡，使其平衡，右旋转，右旋转前先检查L->bf，
//如果为RH，L要先进行左旋转，使T->leftC->bf和T->bf一致
void leftBal(bstNode *T)
{
    bstNode *L, *Lr;
    L = T->leftC;
    Lr = L->rightC;
    switch (L->bf)
    {
    case 1:
        L->bf = T->bf = 0;
        rightRot(T);
        break;
    case -1:
        switch (Lr->bf)
        {
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
        break;
    }
}

//T 的右边高，不平衡，使其平衡，左旋转，左旋转前先检查R->bf,
//如果为LH，R要先进行右旋转，使T->rightC->bf和T->bf一致
void rightBal(bstNode *T)
{
    bstNode *R, *Rl;
    R = T->rightC;
    Rl = R->leftC;
    switch (R->bf)
    {
    case -1:
        R->bf = T->bf = 0;
        leftRot(T);
        break;
    case 1:
        switch (R->bf)
        {
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
        break;
    }
}

//寻找Successor
bstNode *findSuc(bstNode *T, bstNode *p, int q)
{
    if (T == NULL)
    {
        return p;
    }
    else if (q == T->value)
    {
        return T;
    }
    else if (q < T->value)
    {
        p = T;
        return findSuc(T->leftC, p, q);
    }
    else
    {
        return findSuc(T->rightC, p, q);
    }
}

//寻找Predecessor
bstNode *findPred(bstNode *T, bstNode *p, int q)
{
    if (T == NULL)
    {
        return p;
    }
    else if (q == T->value)
    {
        return T;
    }
    else if (q < T->value)
    {
        return findPred(T->leftC, p, q);
    }
    else
    {
        p = T;
        return findPred(T->rightC, p, q);
    }
}

//往平衡二叉树上插入节点
void treeInsert(bstNode *T, int val)
{
    bool inserted = true;
    while (true)
    {
        if (val < T->value)
        {
            if (T->leftC != NULL)
            {
                T = T->leftC;
            }
            else
            {
                T->leftC = new bstNode{val, 0, NULL, NULL};
                break;
            }
        }
        else if (val > T->value)
        {
            if (T->rightC != NULL)
            {
                T = T->rightC;
            }
            else
            {
                T->rightC = new bstNode{val, 0, NULL, NULL};
                break;
            }
        }
        else
        {
            inserted = false;
            break;
        }
    }
    if (inserted)
    {
        switch (T->bf) //T插入结点后，检测平衡因子，根据情况，做相应的修改和旋转
        {
        case 1:
            leftBal(T); //插入后左边不平衡了，让其左平衡
            inserted = false;
            break;
        case 0:
            T->bf = 1;
            inserted = true;
            break;
        case -1:
            T->bf = 0;
            inserted = false;
            break;
        }
    }
    else //往右子树搜索进行插入
    {
        if (!Insert(&(*T)->rightC), val, inserted) //树中有相同的结点
        {
            *inserted = false;
            return false;
        }
        if (*inserted) //插入到右子树中且长高了
        {
            switch ((*T)->bf) //T插入结点后，检测平衡因子，根据情况，做相应的修改和旋转
            {
            case LH:
                (*T)->bf = EH;
                *inserted = false;
                break;
            case EH:
                (*T)->bf = RH;
                *inserted = true;
                break;
            case RH:
                R_Balance(T); //插入后右边不平衡了，让其右平衡
                *inserted = false;
                break;
            }
        }
    }
}