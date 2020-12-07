#include <iostream>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, *seq = new int[20000010], front = 0, rear = 0, env;
    char order;
    cin >> n;
    // scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> order;
        // scanf("%s", &order);
        switch (order)
        {
        case 'E':
            cin >> env;
            // scanf("%d", &env);
            seq[rear] = env;
            rear++;
            break;
        case 'D':
            front++;
            break;
        case 'A':
            if (front != rear)
            {
                cout << seq[front];
                // printf("%d", seq[front]);
            }
            cout << "\n";
            // printf("\n");
            break;
        }
    }
    for (int i = front; i < rear; i++)
    {
        cout << seq[i] << " ";
        // printf("%d ", seq[i]);
    }
    return 0;
}