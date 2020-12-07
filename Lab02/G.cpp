#include <iostream>
using namespace std;
typedef long long ll;
int n, k, m;
ll biggerThanX(ll x, int ipt[]);

int main()
{
    int t;
    cin >> t;
    for (int s = 0; s < t; s++)
    {
        cin >> n >> k >> m;
        int ipt[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ipt[i];
        }
        ll ed = (ll)1e18, st = 0, mid;
        while (st < ed)
        {
            mid = (st + ed) / 2;
            if (biggerThanX(mid, ipt) <= m - 1)
            {
                ed = mid;
            }
            else
            {
                st = mid + 1;
            }
        }
        cout << ed << endl;
    }
}

ll biggerThanX(ll x, int ipt[])
{
    int j = 0, times = 0;
    ll num = 0;
    for (int i = 0; i < n; i++)
    {
        if (ipt[i] > x)
        {
            times++;
        }
        if (times == k)
        {
            num += n - i;
            while (ipt[j] <= x)
            {
                num += n - i;
                j++;
            }
            j++;
            times--;
        }
    }
    return num;
}