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
    int dis;
    bool visited;
    Node *head;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v, w, front = 0, rear = 0;
    cin >> n >> m;
    GraphNode **grp = new GraphNode *[n + m + 1], *cur, **queue = new GraphNode *[n + m];
    Node *temp, *curNode;
    int count = n + 1;
    for (int i = 1; i <= n + m; i++)
    {
        temp = new Node{-1, NULL, NULL};
        temp->next = temp->pre = temp;
        grp[i] = new GraphNode{i, 0, false, temp};
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        if (w == 2)
        {
            temp = new Node{count, grp[u]->head, grp[u]->head->pre};
            grp[u]->head->pre->next = temp;
            grp[u]->head->pre = temp;
            u = count;
            count++;
        }
        temp = new Node{v, grp[u]->head, grp[u]->head->pre};
        grp[u]->head->pre->next = temp;
        grp[u]->head->pre = temp;
    }
    queue[rear++] = grp[1];
    grp[1]->visited = true;
    while (rear > front)
    {
        curNode = queue[front]->head->next;
        while (curNode->value != -1)
        {
            if (!grp[curNode->value]->visited)
            {
                queue[rear++] = grp[curNode->value];
                grp[curNode->value]->dis = queue[front]->dis + 1;
                grp[curNode->value]->visited = true;
                if (curNode->value == n)
                {
                    cout << grp[curNode->value]->dis;
                    return 0;
                }
            }
            curNode = curNode->next;
        }
        front++;
    }
    cout << "-1";
    return 0;
}
