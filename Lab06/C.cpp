#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char ans;
    int n, q, s, k, lgh, j, kk, l1, l2, count = 0, minl;
    cin >> n;
    string sts[n], newstr;
    for (int i = 0; i < n; i++)
    {
        cin >> sts[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> s >> k >> ans;
        s--;
        k--;
        minl = sts[s].length() > sts[k].length() ? sts[k].length() : sts[s].length();
        lgh = sts[s].length() + sts[k].length();
        int pi[lgh];
        newstr = sts[s] + sts[k];
        pi[0] = 0;
        j = 1, kk = 0;
        while (j < lgh)
        {
            if (newstr[kk] == newstr[j])
            {
                kk++;
                pi[j] = kk;
                j++;
            }
            else if (kk == 0)
            {
                pi[j] = 0;
                j++;
            }
            else
            {
                kk = pi[kk - 1];
            }
        }
        l1 = pi[lgh - 1] > minl ? minl : pi[lgh - 1];
        newstr = sts[k] + sts[s];
        pi[0] = 0;
        j = 1, kk = 0;
        while (j < lgh)
        {
            if (newstr[kk] == newstr[j])
            {
                kk++;
                pi[j] = kk;
                j++;
            }
            else if (kk == 0)
            {
                pi[j] = 0;
                j++;
            }
            else
            {
                kk = pi[kk - 1];
            }
        }
        l2 = pi[lgh - 1] > minl ? minl : pi[lgh - 1];
        if (l1 > l2)
        {
            if (ans == '>')
            {
                count++;
            }
        }
        else if (l1 < l2)
        {
            if (ans == '<')
            {
                count++;
            }
        }
        else
        {
            if (ans == '=')
            {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}