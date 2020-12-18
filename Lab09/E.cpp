#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *pre;
};

struct GraphNode
{
    int idx;
    bool visiteda;
    bool visitedb;
    Node *head;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, u, v, front = 0, rear = 0, counta, countb;
    long long rst;
    cin >> n >> m >> a >> b;
    GraphNode **grp = new GraphNode *[n + 1], *cur, **queue = new GraphNode *[n];
    Node *temp, *curNode;
    for (int i = 1; i <= n; i++)
    {
        temp = new Node{-1, NULL, NULL};
        temp->next = temp->pre = temp;
        grp[i] = new GraphNode{i, false, false, temp};
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        temp = new Node{v, grp[u]->head, grp[u]->head->pre};
        grp[u]->head->pre->next = temp;
        grp[u]->head->pre = temp;
        temp = new Node{u, grp[v]->head, grp[v]->head->pre};
        grp[v]->head->pre->next = temp;
        grp[v]->head->pre = temp;
    }
    queue[rear++] = grp[a];
    grp[b]->visiteda = grp[a]->visiteda = true;
    while (rear > front)
    {
        curNode = queue[front]->head->next;
        while (curNode->value != -1)
        {
            if (!grp[curNode->value]->visiteda)
            {
                queue[rear++] = grp[curNode->value];
                grp[curNode->value]->visiteda = true;
            }
            curNode = curNode->next;
        }
        front++;
    }
    rear++;
    counta = n - rear;
    rear = front = 0;
    queue[rear++] = grp[b];
    grp[b]->visitedb = grp[a]->visitedb = true;
    while (rear > front)
    {
        curNode = queue[front]->head->next;
        while (curNode->value != -1)
        {
            if (!grp[curNode->value]->visitedb)
            {
                queue[rear++] = grp[curNode->value];
                grp[curNode->value]->visitedb = true;
            }
            curNode = curNode->next;
        }
        front++;
    }
    rear++;
    countb = n - rear;
    rst = (long long)counta * (long long)countb;
    cout << rst;
    return 0;
}