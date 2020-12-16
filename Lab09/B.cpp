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
    bool visited;
    Node *head;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    bool hasCir;
    cin >> n >> m;
    int *stk = new int[m];
    int *grp = new int[m + 1];
    while (m--)
    {
        
    }
    return 0;
}