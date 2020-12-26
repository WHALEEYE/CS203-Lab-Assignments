#include <iostream>
using namespace std;

int main()
{
    int n, s, k, st, ed, md, n1, n2;
    long long opt = 0;
    cin >> n >> s;
    int ipt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ipt[i];
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            if (s - ipt[i] - ipt[j])
            {
                k = s - ipt[i] - ipt[j];
                st = j + 1;
                ed = n - 1;
                while (st < ed)
                {
                    md = (st + ed) / 2;
                    if (ipt[md] >= k)
                    {
                        ed = md;
                    }
                    else
                    {
                        st = md + 1;
                    }
                }
                if (ipt[st] == k)
                {
                    n1 = st;
                }
                else
                {
                    continue;
                }
                st = j + 1;
                ed = n - 1;
                while (st < ed)
                {
                    md = (st + ed) / 2 + 1;
                    if (ipt[md] <= k)
                    {
                        st = md;
                    }
                    else
                    {
                        ed = md - 1;
                    }
                }
                if (ipt[st] == k)
                {
                    n2 = st;
                }
                opt += n2 - n1 + 1;
            }
        }
    }
    cout << opt << endl;
}