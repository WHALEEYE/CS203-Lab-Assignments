#include <iostream>
using namespace std;

int main()
{
    int n, t, st, ed, md, e, ot;
    cin >> n >> t;
    int d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i < t; i++)
    {
        st = 0;
        ed = n - 1;
        cin >> e;
        while (st <= ed)
        {
            md = (st + ed) / 2;
            ot = e - d[md];
            if (d[md] == e)
            {
                cout << "Accept" << endl;
                break;
            }
            else if (d[md] > e)
            {
                ed = md - 1;
            }
            else
            {
                st = md + 1;
            }
        }
        if (ot > 0)
        {
            cout << ot << endl;
        }
        else if (ot < 0)
        {
            cout << e - d[md - 1] << endl;
        }
    }
}