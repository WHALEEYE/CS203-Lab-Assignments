#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *pre;
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, env;
    cin >> n;
    char order;
    bool exist = false;
    Node *temp, *head, *tail, *cur;
    for (int i = 0; i < n; i++)
    {
        cin >> order;
        switch (order)
        {
        case 'E':
            cin >> env;
            if (!exist)
            {
                head = new Node{env, NULL, NULL};
                tail = head;
                head->next = head->pre = head;
                exist = true;
            }
            else
            {
                temp = new Node{env, head, tail};
                tail->next = temp;
                head->pre = temp;
                tail = temp;
            }
            break;
        case 'D':
            if (head->next == head)
            {
                exist = false;
                break;
            }
            head->next->pre = head->pre;
            head->pre->next = head->next;
            head = head->next;
            break;
        case 'A':
            if (exist)
            {
                cout << head->value;
            }
            cout << "\n";
            break;
        }
    }
    if (exist)
    {
        cur = head;
        do
        {
            cout << cur->value << " ";
            cur = cur->next;
        } while (cur != head);
    }
    cout << "\n";
    return 0;
}
