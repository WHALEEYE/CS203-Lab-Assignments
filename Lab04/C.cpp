#include <iostream>
using namespace std;

struct Node
{
    int coe;
    int expo;
    Node *next;
};

int main()
{
    int t, n, coe, expo;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        bool first = true, no = true;
        Node *head = new Node{0, -1, head};
        Node *tail = head;
        Node *tmp, *cur = head;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d%d", &coe, &expo);
            tmp = new Node{coe, expo, NULL};
            tail->next = tmp;
            tail = tmp;
        }
        tail->next = head;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d%d", &coe, &expo);
            while (true)
            {
                if (cur->expo == expo)
                {
                    cur->coe += coe;
                    break;
                }
                else if (cur->next->expo > expo || cur->next->expo == -1)
                {
                    tmp = new Node{coe, expo, NULL};
                    tmp->next = cur->next;
                    cur->next = tmp;
                    break;
                }
                cur = cur->next;
            }
        }
        cur = head->next;
        while (true)
        {
            if (cur->coe != 0 && first)
            {
                if ((cur->coe != 1 && cur->coe != -1) && cur->expo != 1 && cur->expo != 0)
                {
                    printf("%dx^%d", cur->coe, cur->expo);
                }
                else if (cur->expo != 1 && cur->expo != 0)
                {
                    if (cur->coe == -1)
                    {
                        printf("-");
                    }
                    printf("x^%d", cur->expo);
                }
                else if ((cur->coe != 1 && cur->coe != -1) && cur->expo == 1)
                {
                    printf("%dx", cur->coe);
                }
                else if ((cur->coe == 1 || cur->coe == -1) && cur->expo == 1)
                {
                    if (cur->coe == -1)
                    {
                        printf("-");
                    }
                    printf("x");
                }
                else
                {
                    printf("%d", cur->coe);
                }
                first = false;
                no = false;
            }
            else if (cur->coe != 0 && !first)
            {
                if (cur->coe > 0)
                {
                    printf("+");
                }
                if ((cur->coe != 1 && cur->coe != -1) && cur->expo != 1)
                {
                    printf("%dx^%d", cur->coe, cur->expo);
                }
                else if (cur->expo != 1)
                {
                    if (cur->coe == -1)
                    {
                        printf("-");
                    }
                    printf("x^%d", cur->expo);
                }
                else if (cur->coe != 1 && cur->coe != -1)
                {
                    printf("%dx", cur->coe);
                }
                else
                {
                    if (cur->coe == -1)
                    {
                        printf("-");
                    }
                    printf("x");
                }
                no = false;
            }
            if (cur->next == head)
            {
                break;
            }
            cur = cur->next;
        }
        if (no)
        {
            printf("0");
        }
        printf("\n");
    }
    return 0;
}