#include <iostream>
using namespace std;

template <class K>
class SmallHeap
{
public:
    int rear, con, curidx, min;
    K *hp, temp;
    SmallHeap(int con) : rear(0), con(con)
    {
        hp = new K[con];
    }

    K deleteTop()
    {
        if (rear == 0)
        {
            return (K)NULL;
        }
        rear--;
        K top = hp[0];
        hp[0] = hp[rear];
        curidx = 0;
        while (true)
        {
            if (2 * curidx + 2 >= rear)
            {
                min = 2 * curidx + 1;
            }
            else
            {
                min = hp[2 * curidx + 1] > hp[2 * curidx + 2] ? (2 * curidx + 2) : (2 * curidx + 1);
            }
            if (hp[curidx] > hp[min])
            {
                temp = hp[curidx];
                hp[curidx] = hp[min];
                hp[min] = temp;
                curidx = min;
            }
            else
            {
                break;
            }
            if (2 * curidx + 1 >= rear)
            {
                break;
            }
        }
        return top;
    }

    void insertHeap(K val)
    {
        curidx = rear;
        hp[rear++] = val;
        while (curidx > 0)
        {
            if (hp[curidx] < hp[(curidx - 1) / 2])
            {
                temp = hp[curidx];
                hp[curidx] = hp[(curidx - 1) / 2];
                hp[(curidx - 1) / 2] = temp;
                curidx = (curidx - 1) / 2;
            }
            else
            {
                break;
            }
        }
    }
};

struct Node
{
    int value;
    Node *next;
    Node *pre;
};

struct GraphNode
{
    int idx;
    int pointed;
    Node *head;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    GraphNode **grp = new GraphNode *[n + 1], *cur;
    SmallHeap<int> *hp = new SmallHeap<int>(n);
    Node *temp, *curNode;
    for (int i = 1; i <= n; i++)
    {
        temp = new Node{-1, NULL, NULL};
        temp->next = temp->pre = temp;
        grp[i] = new GraphNode{i, 0, temp};
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        temp = new Node{b, grp[a]->head, grp[a]->head->pre};
        grp[b]->pointed++;
        grp[a]->head->pre->next = temp;
        grp[a]->head->pre = temp;
    }
    for (int i = 1; i <= n; i++)
    {
        if (grp[i]->pointed == 0)
        {
            hp->insertHeap(i);
        }
    }
    while (hp->rear != 0)
    {
        cur = grp[hp->deleteTop()];
        curNode = cur->head->next;
        while (curNode != cur->head)
        {
            grp[curNode->value]->pointed--;
            if (grp[curNode->value]->pointed == 0)
            {
                hp->insertHeap(curNode->value);
            }
            curNode = curNode->next;
        }
        cout << cur->idx << " ";
    }
    return 0;
}