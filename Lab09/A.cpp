#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, **gra, ver1, ver2;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        gra = new int *[n];
        for (int i = 0; i < n; i++)
        {
            gra[i] = new int[n]();
        }
        while (m--)
        {
            cin >> ver1 >> ver2;
            gra[ver1 - 1][ver2 - 1]++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << gra[i][j] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}