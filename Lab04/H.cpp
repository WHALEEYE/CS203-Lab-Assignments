#include <iostream>
using namespace std;

struct Node
{
    int con;
    Node *next;
    Node *pre;
};

int main()
{
    int n, m, dig, ins, pos;
    char order, trash;
    Node *temp, *head = new Node{-1, NULL, NULL}, *cur, *tail = head;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dig);
        temp = new Node{dig, NULL, tail};
        tail->next = temp;
        tail = temp;
    }
    tail->next = head;
    head->pre = tail;
    for (int i = 0; i < m; i++)
    {
        scanf("%s", &order);
        switch (order)
        {
        case 'i':
            scanf("%d%d", &pos, &ins);
            cur = head->next;
            for (int j = 1; j < pos; j++)
            {
                cur = cur->next;
            }
            temp = new Node{ins, cur, cur->pre};
            cur->pre->next = temp;
            cur->pre = temp;
            break;
        case 'q':
            scanf("%d", &pos);
            cur = head->next;
            for (int j = 1; j < pos; j++)
            {
                cur = cur->next;
            }
            printf("%d\n", cur->con);
            break;
        case 'r':
            scanf("%d", &pos);
            cur = head->next;
            for (int j = 1; j < pos; j++)
            {
                cur = cur->next;
            }
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            break;
        }
    }
    return 0;
}