#include <iostream>
using namespace std;

struct LLNode
{
    int value;
    LLNode *next;
    LLNode *pre;
};

struct TreeNode
{
    int lev;
    int value;
    bool visited;
    bool conq;
    LLNode *head;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, val1, val2, pos, rear, front, farthest, maxl;
        LLNode *tmp, *cur;
        cin >> n >> k;
        bool isLast = false;
        TreeNode **tree = new TreeNode *[n + 1];
        for (int i = 1; i < n + 1; i++)
        {
            tmp = new LLNode{-1, NULL, NULL};
            tmp->next = tmp->pre = tmp;
            tree[i] = new TreeNode{0, i, false, false, tmp};
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> val1 >> val2;
            tmp = new LLNode{val2, tree[val1]->head, tree[val1]->head->pre};
            tree[val1]->head->pre->next = tmp;
            tree[val1]->head->pre = tmp;
            tmp = new LLNode{val1, tree[val2]->head, tree[val2]->head->pre};
            tree[val2]->head->pre->next = tmp;
            tree[val2]->head->pre = tmp;
        }
        for (int i = 0; i < k; i++)
        {
            cin >> pos;
            tree[pos]->conq = true;
        }
        TreeNode **queue = new TreeNode *[n];
        front = 0;
        queue[0] = tree[1];
        queue[0]->visited = true;
        rear = 1;
        while (rear < n)
        {
            cur = queue[front]->head;
            while (cur->next->value != -1)
            {
                if (!tree[cur->next->value]->visited)
                {
                    queue[rear] = tree[cur->next->value];
                    queue[rear]->visited = true;
                    rear++;
                }
                cur = cur->next;
            }
            front++;
        }
        while (true)
        {
            rear--;
            if (queue[rear]->conq)
            {
                farthest = queue[rear]->value;
                break;
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            tree[i]->visited = false;
        }
        front = 0;
        rear = 1;
        queue[0] = tree[farthest];
        queue[0]->lev = 1;
        queue[0]->visited = true;
        while (rear < n)
        {
            cur = queue[front]->head;
            while (cur->next->value != -1)
            {
                if (!tree[cur->next->value]->visited)
                {
                    queue[rear] = tree[cur->next->value];
                    queue[rear]->visited = true;
                    queue[rear]->lev = queue[front]->lev + 1;
                    rear++;
                }
                cur = cur->next;
            }
            front++;
        }
        while (true)
        {
            rear--;
            if (queue[rear]->conq)
            {
                maxl = queue[rear]->lev;
                break;
            }
        }
        cout << maxl / 2 << endl;
    }
    return 0;
}