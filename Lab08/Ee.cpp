#include <iostream>
using namespace std;

template <class K>
struct bstNode
{
    K value;
    int bf; //平衡因子，值为该节点左子树高度减右子树高度
    bstNode<K> *parent;
    bstNode<K> *leftC;
    bstNode<K> *rightC;
};

template <class K>
class AVLTree
{
private:
    bool taller, lower;
    bstNode<K> *tempu, *tempv;

public:
    bstNode<K> *root;
    AVLTree(K rootval)
    {
        this->root = new bstNode<K>{rootval, 0, NULL, NULL, NULL};
    }

    //左旋转
    void leftRot(bstNode<K> *T)
    {
        bstNode<K> *R = T->rightC;
        if (R->leftC != NULL)
        {
            R->leftC->parent = T;
            T->rightC = R->leftC;
        }
        if (T->parent != NULL)
        {
            if (T->parent->leftC == T)
            {
                T->parent->leftC = R;
            }
            else
            {
                T->parent->rightC = R;
            }
        }
        R->parent = T->parent;
        T->parent = R;
        R->leftC = T;
        if (T == root)
        {
            root = R;
        }
    }

    //右旋转
    void rightRot(bstNode<K> *T)
    {
        bstNode<K> *L = T->leftC;
        if (L->rightC != NULL)
        {
            L->rightC->parent = T;
            T->leftC = L->rightC;
        }
        if (T->parent != NULL)
        {
            if (T->parent->leftC == T)
            {
                T->parent->leftC = L;
            }
            else
            {
                T->parent->rightC = L;
            }
        }
        L->parent = T->parent;
        T->parent = L;
        L->rightC = T;
        if (T == root)
        {
            root = L;
        }
    }

    //T 的左边高，不平衡，使其平衡，右旋转，右旋转前先检查L->bf，
    //如果为RH，L要先进行左旋转，使T->leftC->bf和T->bf一致
    void leftHigh(bstNode<K> *T)
    {
        bstNode<K> *L, *Lr;
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
    void rightHigh(bstNode<K> *T)
    {
        bstNode<K> *R, *Rl;
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
    bstNode<K> *findSuc(bstNode<K> *T, bstNode<K> *p, K q)
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
    bstNode<K> *findPred(bstNode<K> *T, bstNode<K> *p, K q)
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

    void treeInsert(K val)
    {
        bstNode<K> *T = root, *cld;
        while (true)
        {
            if (val == T->value)
            {
                return;
            }
            else if (val < T->value)
            {
                if (T->leftC == NULL)
                {
                    break;
                }
                T = T->leftC;
            }
            else
            {
                if (T->rightC == NULL)
                {
                    break;
                }
                T = T->rightC;
            }
        }
        if (val < T->value)
        {
            T->leftC = new bstNode<K>{val, 0, T, NULL, NULL};
            switch (T->bf)
            {
            case -1:
                T->bf = 0;
                taller = false;
                break;
            case 0:
                T->bf = 1;
                taller = true;
                break;
            }
        }
        else
        {
            T->rightC = new bstNode<K>{val, 0, T, NULL, NULL};
            switch (T->bf)
            {
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
        while (T != root)
        {
            cld = T;
            T = T->parent;
            if (T->leftC == cld)
            {
                if (taller)
                {
                    switch (T->bf)
                    {
                    case -1:
                        T->bf = 0;
                        taller = false;
                        break;
                    case 0:
                        T->bf = 1;
                        taller = true;
                        break;
                    case 1:
                        leftHigh(T);
                        taller = false;
                        break;
                    }
                }
            }
            else
            {
                if (taller)
                {
                    switch (T->bf)
                    {
                    case -1:
                        rightHigh(T);
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

    void treeDelete(K val)
    {
        bstNode<K> *T = root, *temp, *cld, *U;
        while (val != T->value)
        {
            if (val < T->value)
            {
                T = T->leftC;
            }
            else
            {
                T = T->rightC;
            }
        }
        if (T->leftC == NULL && T->rightC == NULL) //T本身为叶子节点 直接删除T即可
        {
            temp = T;
            T = T->parent;
            if (T == NULL)
            {
                root = NULL;
                delete temp;
                return;
            }
            if (T->leftC == temp)
            {
                T->leftC = NULL;
                switch (T->bf)
                {
                case -1:
                    rightHigh(T);
                    lower = false;
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
            else
            {
                T->rightC = NULL;
                switch (T->bf)
                {
                case -1:
                    T->bf = 0;
                    lower = true;
                    break;
                case 0:
                    T->bf = 1;
                    lower = false;
                    break;
                case 1:
                    leftHigh(T);
                    lower = false;
                    break;
                }
            }
            delete temp;
            reBalDel(T, lower);
        }
        else if (T->rightC == NULL) // T无右子树，直接将左节点（因为平衡，所以左子树只有一个节点）接上
        {
            U = T->leftC;
            temp = T;
            T = T->parent;
            U->parent = T;
            if (T == NULL)
            {
                root = U;
                return;
            }
            if (T->leftC == temp)
            {
                T->leftC = U;
            }
            else
            {
                T->rightC = U;
            }
            delete temp;
            reBalDel(U, true);
        }
        else //又有左子树又有右子树，需要先找到successor
        {
            U = findSuc(T);
            T->value = U->value;   //将T用U替换，这里表示为value的替换
            if (U->rightC == NULL) //U无右子树，即U为叶子节点（Successor不可能有左子树）
            {
                temp = U;
                U = U->parent;
                if (U->leftC == temp)
                {
                    U->leftC = NULL;
                    switch (U->bf)
                    {
                    case -1:
                        rightHigh(U);
                        lower = false;
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
                }
                else
                {
                    U->rightC = NULL;
                    switch (U->bf)
                    {
                    case -1:
                        U->bf = 0;
                        lower = true;
                        break;
                    case 0:
                        U->bf = 1;
                        lower = false;
                        break;
                    case 1:
                        leftHigh(U);
                        lower = false;
                        break;
                    }
                }
                delete temp;    
                reBalDel(U, lower);
            }
            else
            {
                temp = U;
                U = U->rightC;
                U->parent = temp->parent;
                if (temp->parent->rightC == temp)
                {
                    temp->parent->rightC = U;
                }
                else
                {
                    temp->parent->leftC = U;
                }
                lower = true;
                delete temp;
            }
            while (U != root)
            {
                cld = U;
                U = U->parent;
                if (U->leftC == cld)
                {
                    if (lower)
                    {
                        switch (T->bf)
                        {
                        case -1:
                            T->bf = 0;
                            taller = false;
                            break;
                        case 0:
                            T->bf = 1;
                            taller = true;
                            break;
                        case 1:
                            leftHigh(T);
                            taller = false;
                            break;
                        }
                    }
                }
                else
                {
                    if (taller)
                    {
                        switch (T->bf)
                        {
                        case -1:
                            rightHigh(T);
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
    }

    void reBalDel(bstNode<K> *T, bool lower)
    {
        bstNode<K> *cld;
        cld = T;
        T = T->parent;
        while (T != NULL)
        {
            if (T->leftC == cld)
            {
                if (lower)
                {
                    switch (T->bf)
                    {
                    case -1:
                        rightHigh(T);
                        lower = false;
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
            }
            else
            {
                if (lower)
                {
                    switch (T->bf)
                    {
                    case -1:
                        T->bf = 0;
                        lower = true;
                        break;
                    case 0:
                        T->bf = 1;
                        lower = false;
                        break;
                    case 1:
                        leftHigh(T);
                        lower = false;
                        break;
                    }
                }
            }
        }
    }

    // bool nodeDelete(bstNode<K> *T, K val)
    // {
    //     if (val < T->value)
    //     {
    //         if (T->leftC->value == val)
    //         {
    //             tempu = T->leftC;
    //             if (tempu->leftC == NULL && tempu->rightC == NULL)
    //             {
    //                 delete tempu;
    //                 T->leftC = NULL;
    //                 lower = true;
    //                 return true;
    //             }
    //             else if (tempu->rightC != NULL)
    //             {
    //             }
    //         }
    //         nodeDelete(T->leftC, val);
    //         if (taller)
    //         {
    //             switch (T->bf)
    //             {       // 检查结点的平衡因子
    //             case 1: // 原本结点的左子树比右子树高，且在左子树中插入了，需要做左平衡处理，处理之后树的高度不变
    //                 leftHigh(T);
    //                 taller = false;
    //                 break;
    //             case 0: // 左右子树同样高，在左子树中插入，只是树变高了、平衡因子变为1，但当前不用做平衡处理
    //                 T->bf = 1;
    //                 taller = true;
    //                 break;
    //             case -1: // 右子树比左子树高，在左子树中插入，树的高度不变，当前结点的平衡因子变为0
    //                 T->bf = 0;
    //                 taller = false;
    //                 break;
    //             }
    //         }
    //     }
    //     else
    //     { // ③
    //         if (T->rightC == NULL)
    //         { // 检查右子树
    //             bstNode<K> *q = new bstNode<K>{val, 0, NULL, NULL};
    //             T->rightC = q;
    //             switch (T->bf)
    //             {
    //             case 0:
    //                 T->bf = -1;
    //                 taller = true;
    //                 break;
    //             case 1:
    //                 T->bf = 0;
    //                 taller = false;
    //                 break;
    //             }
    //             return true;
    //         }
    //         nodeDelete(T->rightC, val);
    //         if (taller)
    //         {
    //             switch (T->bf)
    //             {
    //             case 1:
    //                 T->bf = 0;
    //                 taller = false;
    //                 break;
    //             case 0:
    //                 T->bf = -1;
    //                 taller = true;
    //                 break;
    //             case -1:
    //                 rightHigh(T);
    //                 taller = false;
    //                 break;
    //             }
    //         }
    //     }
    //     return true;
    // }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    AVLTree<int> *a = new AVLTree<int>(80);
    a->treeInsert(70);
    a->treeInsert(60);
    a->treeInsert(50);
    cout << a->root->leftC->leftC->value << '\n';
    return 0;
}
