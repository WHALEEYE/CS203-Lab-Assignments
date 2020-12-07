#include <iostream>
using namespace std;

int main()
{
    int cases, n, m;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> n >> m;
        if (n == m & m == 1)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Alice" << endl;
        }
    }
    return 0;
}