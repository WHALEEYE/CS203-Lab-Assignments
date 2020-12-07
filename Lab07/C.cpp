#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *pre;
};

Node *none = new Node{-1, NULL, NULL};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n, val, rear, k;
    Node *head, *tmp, *cur, **qu = new Node *[100010];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        Node **tree = new Node *[n + 1];
        for (int j = 0; j <= n; j++)
        {
            tree[j] = none;
        }
        tmp = new Node{-1, NULL, NULL};
        tmp->next = tmp->pre = tmp;
        tree[0] = tmp;
        tmp = new Node{1, tree[0], tree[0]};
        tree[0]->next = tmp;
        tree[0]->pre = tmp;
        for (int j = 1; j < n; j++)
        {
            cin >> val;
            if (tree[val] == none)
            {
                tmp = new Node{-1, NULL, NULL};
                tmp->next = tmp->pre = tmp;
                tree[val] = tmp;
            }
            tmp = new Node{j + 1, tree[val], tree[val]->pre};
            tree[val]->pre->next = tmp;
            tree[val]->pre = tmp;
        }
        rear = 2;
        k = 0;
        qu[0] = new Node{0, NULL, NULL};
        qu[1] = tree[0]->next;
        while (k < rear)
        {
            if (tree[qu[k]->value] != none && qu[rear - 1]->next != tree[qu[k]->value])
            {
                qu[rear] = qu[rear - 1]->next;
                rear++;
            }
            else if (k + 1 <= n && tree[qu[k + 1]->value] != none)
            {
                k++;
                qu[rear] = tree[qu[k]->value]->next;
                rear++;
            }
            else
            {
                k++;
            }
        }
        for (int j = 1; j < rear; j++)
        {
            cout << qu[j]->value << " ";
        }
        cout << "\n";
    }
    return 0;
}