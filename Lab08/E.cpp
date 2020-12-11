#include <iostream>
using namespace std;
typedef struct bstNode
{
    int data;
    int bf;
    bstNode *lchild, *rchild;
};
//左旋转
void leftRot(bstNode *T)
{
    bstNode *R = T->rchild;
    T->rchild = R->lchild;
    R->lchild = T;
}
//右旋转
void rightRot(bstNode *T)
{
    bstNode *L = T->lchild;
    T->lchild = L->rchild;
    L->rchild = T;
    return;
}
#define LH +1
#define EH 0
#define RH -1
//T 的左边高，不平衡，使其平衡，右旋转，右旋转前先检查L->bf，
//如果为RH，L要先进行左旋转，使T->lchild->bf和T->bf一致
void leftBal(bstNode *T)
{
    bstNode *L, *Lr;
    L = T->lchild;
    Lr = L->rchild;
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
//如果为LH，R要先进行右旋转，使T->rchild->bf和T->bf一致
void RightBalance(BiTree *T)
{
    BiTree R, Rl;
    R = (*T)->rchild;
    Rl = R->lchild;
    switch (R->bf)
    {
    case RH:
        R->bf = (*T)->bf = EH;
        L_Rotate(T);
        break;
    case LH:
        switch (R->bf)
        {
        case LH:
            R->bf = RH;
            (*T)->bf = EH;
            break;
        case EH:
            R->bf = (*T)->bf = EH;
            break;
        case RH:
            R->bf = EH;
            (*T)->bf = LH;
            break;
        }
        Rl->bf = EH;
        R_Rotate(&R);
        L_Rotate(T);
        break;
    }
}
//往平衡二叉树上插入结点
bool InsertAVL(BiTree *T, int data, bool *taller)
{
    if (*T == NULL) //找到插入位置
    {
        *T = (BiTree)malloc(sizeof(bstNode));
        (*T)->bf = EH;
        (*T)->rchild = (*T)->lchild = NULL;
        (*T)->data = data;
        *taller = true;
    }
    else
    {
        if (data == (*T)->data) //树中有相同的结点数据直接返回
        {
            *taller = false;
            return false;
        }
        if (data < (*T)->data) //往左子树搜索进行插入
        {
            if (!InsertAVL(&(*T)->lchild, data, taller)) //树中有相同的结点
            {
                *taller = false;
                return false;
            }
            if (*taller)
            {
                switch ((*T)->bf) //T插入结点后，检测平衡因子，根据情况，做相应的修改和旋转
                {
                case LH:
                    LeftBalance(T); //插入后左边不平衡了，让其左平衡
                    *taller = false;
                    break;
                case EH:
                    (*T)->bf = LH;
                    *taller = true;
                    break;
                case RH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
                }
            }
        }
        else //往右子树搜索进行插入
        {
            if (!Insert(&(*T)->rchild), data, taller) //树中有相同的结点
            {
                *taller = false;
                return false;
            }
            if (*taller) //插入到右子树中且长高了
            {
                switch ((*T)->bf) //T插入结点后，检测平衡因子，根据情况，做相应的修改和旋转
                {
                case LH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
                case EH:
                    (*T)->bf = RH;
                    *taller = true;
                    break;
                case RH:
                    R_Balance(T); //插入后右边不平衡了，让其右平衡
                    *taller = false;
                    break;
                }
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}