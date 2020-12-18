
#include <iostream>
#include <vector>
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
    vector<GraphNode *> grp;
    vector<GraphNode *> queue;
    GraphNode *cur;
    Node *temp, *curNode;
    int count = n + 1;
    grp.push_back(new GraphNode{-1, 0, false, NULL});
    for (int i = 1; i <= n; i++)
    {
        temp = new Node{-1, NULL, NULL};
        temp->next = temp->pre = temp;
        grp.push_back(new GraphNode{i, 0, false, temp});
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        if (w == 2)
        {
            temp = new Node{-1, NULL, NULL};
            temp->next = temp->pre = temp;
            grp.push_back(new GraphNode{count, 0, false, temp});
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
    rear++;
    queue.push_back(grp[1]);
    grp[1]->visited = true;
    while (rear > front)
    {
        curNode = queue[front]->head->next;
        while (curNode->value != -1)
        {
            if (!grp[curNode->value]->visited)
            {
                rear++;
                queue.push_back(grp[curNode->value]);
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