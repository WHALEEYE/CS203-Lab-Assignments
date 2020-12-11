#include <iostream>
using namespace std;

struct bstNode
{
    int value;
    int bf; //平衡因子，值为该节点左子树高度减右子树高度
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
bool treeInsert(bstNode *T, int val, bool inserted)
{
    if (T == NULL) //找到插入位置
    {
        T = new bstNode{val, 0, NULL, NULL};
        inserted = true;
    }
    else
    {
        if (val == T->value) //树中有相同的结点数据直接返回
        {
            inserted = false;
            return false;
        }
        if (val < T->value) //往左子树搜索进行插入
        {
            if (!treeInsert(T->leftC, val, inserted)) //树中有相同的结点
            {
                inserted = false;
                return false;
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
        }
        else //往右子树搜索进行插入
        {
            if (!treeInsert(T->rightC, val, inserted)) //树中有相同的结点
            {
                inserted = false;
                return false;
            }
            if (inserted) //插入到右子树中且长高了
            {
                switch (T->bf) //T插入结点后，检测平衡因子，根据情况，做相应的修改和旋转
                {
                case 1:
                    T->bf = 0;
                    inserted = false;
                    break;
                case 0:
                    T->bf = -1;
                    inserted = true;
                    break;
                case -1:
                    rightBal(T); //插入后右边不平衡了，让其右平衡
                    inserted = false;
                    break;
                }
            }
        }
    }
    return true;
}

// public
// boolean insertAVL(BSTNode T, int x)
// { // 以T为根节点的平衡二叉树中插入元素x，成功返回true,失败返回false,taller反应树是否长高
//     if (T == null)
//     { // 只有刚开始插入树为空才会执行这一步
//         root = new BSTNode(x);
//         return true;
//     }
//     if (x == T.getData())
//     { // ①
//         taller = false;
//         return false;
//     }
//     else if (x < T.getData())
//     { // ②
//         if (T.getLchild() == null)
//         { // 检查左子树
//             BSTNode q = new BSTNode(x);
//             T.setLchild(q); // 直接插入
//             q.setParent(T);
//             switch (T.getBf())
//             {
//             case EH:
//                 T.setBf(LH);
//                 taller = true;
//                 break;
//             case RH:
//                 T.setBf(EH);
//                 taller = false;
//                 break;
//             }
//             return true;
//         }
//         if (!insertAVL(T.getLchild(), x))
//         {
//             return false;
//         }
//         if (taller)
//         {
//             switch (T.getBf())
//             {        // 检查结点的平衡因子
//             case LH: // 原本结点的左子树比右子树高，且在左子树中插入了，需要做左平衡处理,处理之后树的高度不变
//                 InLeftBalance(T);
//                 taller = false;
//                 break;
//             case EH: // 左右子树同样高，在左子树中插入，只是树变高了、平衡因子变为1，但当前不用做平衡处理
//                 T.setBf(LH);
//                 taller = true;
//                 break;
//             case RH: // 右子树比左子树高，在左子树中插入，树的高度不变，当前结点的平衡因子变为0
//                 T.setBf(EH);
//                 taller = false;
//                 break;
//             }
//         }
//     }
//     else
//     { // ③
//         if (T.getRchild() == null)
//         { // 检查右子树
//             BSTNode q = new BSTNode(x);
//             T.setRchild(q);
//             q.setParent(T);
//             switch (T.getBf())
//             {
//             case EH:
//                 T.setBf(RH);
//                 taller = true;
//                 break;
//             case LH:
//                 T.setBf(EH);
//                 taller = false;
//                 break;
//             }
//             return true;
//         }
//         if (!insertAVL(T.getRchild(), x))
//         {
//             return false;
//         }
//         if (taller)
//         {
//             switch (T.getBf())
//             {
//             case LH:
//                 T.setBf(EH);
//                 taller = false;
//                 break;
//             case EH:
//                 T.setBf(RH);
//                 taller = true;
//                 break;
//             case RH:
//                 InRightBalance(T);
//                 taller = false;
//                 break;
//             }
//         }
//     }
//     return true;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bstNode *root = new bstNode{100, 0, NULL, NULL};
    treeInsert(root, 80, false);
    cout << root->rightC->value;
    return 0;
}