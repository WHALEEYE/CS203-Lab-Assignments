#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long pl, sl, prod, lgh, p0, s0, ssl;
    string s, pre, suf;
    bool end = false;
    cin >> n;
    cin >> pre;
    suf = pre;
    pl = pre.length();
    sl = ssl = suf.length();
    for (int i = 1; i < n; i++)
    {
        cin >> s;
        if (!end)
        {
            lgh = s.length();
            p0 = pl;
            pl = 0;
            for (int j = 0; j < p0; j++)
            {
                if (j < lgh && pre[j] == s[j])
                {
                    pl = j + 1;
                }
                else
                {
                    break;
                }
            }
            if (pl == 0)
            {
                if (i == n - 1)
                {
                    break;
                }
                else
                {
                    end = true;
                }
            }
            s0 = sl;
            sl = 0;
            for (int j = 1; j <= s0; j++)
            {
                if (j <= lgh && suf[ssl - j] == s[lgh - j])
                {
                    sl = j;
                }
                else
                {
                    break;
                }
            }
            if (sl == 0)
            {
                if (i == n - 1)
                {
                    break;
                }
                else
                {
                    end = true;
                }
            }
        }
    }
    prod = pl * sl;
    cout << prod;
}