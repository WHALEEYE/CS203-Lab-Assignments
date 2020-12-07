#include <iostream>
#include <string>
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
    int *count = new int[100010](), val, max = 0;
    Node **sts = new Node *[300010];
    Node *temp, *cur;
    string order;
    temp = new Node{-1, NULL, NULL};
    temp->next = temp->pre = temp;
    sts[0] = temp;
    while (true)
    {
        cin >> order;
        if (order == "nsdd")
        {
            break;
        }
        else if (order == "put-in")
        {
            cin >> val;
            if (count[val] > max)
            {
                max = count[val];
                temp = new Node{-1, NULL, NULL};
                temp->next = temp->pre = temp;
                sts[max] = temp;
            }
            cur = sts[count[val]];
            temp = new Node{val, cur->next, cur};
            cur->next->pre = temp;
            cur->next = temp;
            count[val]++;
        }
        else if (order == "eat")
        {
            if (sts[max]->next != sts[max])
            {
                cur = sts[max]->next;
                cur->pre->next = cur->next;
                cur->next->pre = cur->pre;
                count[cur->value]--;
                cout << cur->value << "\n";
            }
            else if (max > 0)
            {
                max--;
                cur = sts[max]->next;
                cur->pre->next = cur->next;
                cur->next->pre = cur->pre;
                count[cur->value]--;
                cout << cur->value << "\n";
            }
            else
            {
                cout << "pa\n";
            }
        }
    }
    return 0;
}