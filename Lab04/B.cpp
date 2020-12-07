#include <iostream>
using namespace std;

struct Node
{
    char dgt;
    Node *next;
    Node *pre;
};

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        bool rpl = false;
        Node *tail = new Node{0, NULL, NULL};
        Node *head = new Node{-1, tail, NULL};
        tail->pre = head;
        Node *cur = tail, *temp;
        char d;
        int n;
        scanf("%d", &n);
        getchar();
        for (int j = 0; j < n; j++)
        {
            d = getchar();
            switch (d)
            {
            case 'r':
                if (cur != tail && j != n - 1)
                {
                    cur->next->pre = cur->pre;
                    cur->pre->next = cur->next;
                    cur = cur->next;
                }
                rpl = true;
                break;
            case 'I':
                cur = head->next;
                break;
            case 'H':
                if (cur->pre != head)
                {
                    cur = cur->pre;
                }
                break;
            case 'L':
                if (cur != tail)
                {
                    cur = cur->next;
                }
                break;
            case 'x':
                if (cur != tail)
                {
                    cur->next->pre = cur->pre;
                    cur->pre->next = cur->next;
                    cur = cur->next;
                }
                break;
            default:
                temp = new Node{d, cur, cur->pre};
                cur->pre->next = temp;
                cur->pre = temp;
                if (rpl)
                {
                    cur = temp;
                    rpl = false;
                }
                break;
            }
        }
        cur = head->next;
        while (true)
        {
            if (cur == tail)
            {
                break;
            }
            printf("%c", cur->dgt);
            cur = cur->next;
        }
        printf("\n");
    }
    return 0;
}