#include <iostream>
using namespace std;

struct Node
{
    int value;
    int pos;
    Node *next;
    Node *pre;
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k, n, val, max = 0, l = 0, r = 0;
    cin >> k >> n;
    Node *temp1, *temp2, *front1, *front2, *rear1, *rear2, *cur;
    bool end = false;
    cin >> val;
    temp1 = new Node{val, 0, NULL, NULL};
    temp2 = new Node{val, 0, NULL, NULL};
    temp1->next = temp1->pre = front1 = rear1 = temp1;
    temp2->next = temp2->pre = front2 = rear2 = temp2;
    while (true)
    {
        while ((front2->value - front1->value) <= k)
        {
            max = max > (r - l + 1) ? max : (r - l + 1);
            r++;
            if (r == n)
            {
                end = true;
                break;
            }
            cin >> val;
            bool re1 = false, re2 = false;
            while (val < rear1->value)
            {
                if (rear1->pre == rear1)
                {
                    re1 = true;
                    delete rear1;
                    temp1 = new Node{val, r, NULL, NULL};
                    temp1->next = temp1->pre = temp1;
                    front1 = rear1 = temp1;
                    break;
                }
                else
                {
                    cur = rear1;
                    rear1 = rear1->pre;
                    cur->pre->next = cur->next;
                    cur->next->pre = cur->pre;
                    delete cur;
                }
            }
            if (!re1)
            {
                temp1 = new Node{val, r, rear1->next, rear1};
                rear1->next->pre = temp1;
                rear1->next = temp1;
                rear1 = temp1;
            }
            while (val > rear2->value)
            {
                if (rear2->pre == rear2)
                {
                    re2 = true;
                    delete rear2;
                    temp2 = new Node{val, r, NULL, NULL};
                    temp2->next = temp2->pre = temp2;
                    front2 = rear2 = temp2;
                    break;
                }
                else
                {
                    cur = rear2;
                    rear2 = rear2->pre;
                    cur->pre->next = cur->next;
                    cur->next->pre = cur->pre;
                    delete cur;
                }
            }
            if (!re2)
            {
                temp2 = new Node{val, r, rear2->next, rear2};
                rear2->next->pre = temp2;
                rear2->next = temp2;
                rear2 = temp2;
            }
        }
        if (end)
        {
            break;
        }
        l++;
        if (l == n - 1)
        {
            break;
        }
        if (l > front1->pos)
        {
            cur = front1;
            front1 = front1->next;
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            delete cur;
        }
        if (l > front2->pos)
        {
            cur = front2;
            front2 = front2->next;
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            delete cur;
        }
    }
    cout << max << "\n";
    return 0;
}