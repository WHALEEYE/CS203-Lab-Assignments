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
    int ind;
    Node *head;
};

GraphNode *nil = new GraphNode{-1, NULL};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    GraphNode **grp = new GraphNode *[n + 1], *cur, *tmp;
    Node *temp, *curNode;
    for (int i = 1; i <= n; i++)
    {
        temp = new Node{-1, NULL, NULL};
        temp->next = temp->pre = temp;
        grp[i] = new GraphNode{i, temp};
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
    bool stop = false, empty = false;
    while (!stop)
    {
        stop = true, empty = true;
        for (int i = 1; i <= n; i++)
        {
            if (grp[i] != nil)
            {
                empty = false;
                if (grp[i]->head->next == grp[i]->head)
                {
                    stop = false;
                    grp[i] = nil;
                }
                else if (grp[i]->head->next->next == grp[i]->head)
                {
                    stop = false;
                    tmp = grp[grp[i]->head->next->value];
                    curNode = tmp->head->next;
                    while (curNode != tmp->head)
                    {
                        if (curNode->value == i)
                        {
                            temp = curNode;
                            temp->pre->next = temp->next;
                            temp->next->pre = temp->pre;
                            break;
                        }
                        curNode = curNode->next;
                    }
                    grp[i] = nil;
                }
            }
        }
        if (empty)
        {
            cout << "Good";
            return 0;
        }
    }
    cout << "Bad";
    return 0;
}