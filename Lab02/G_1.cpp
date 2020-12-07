
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e5 + 10;
int n, k;
int pre[MAXN], nxt[MAXN], pos[MAXN];
int l[MAXN], r[MAXN];

void del(int x)
{
    pre[nxt[x]] = pre[x];
    nxt[pre[x]] = nxt[x];
}

ll cal(int x)
{
    int c1 = 0, c2 = 0;
    for (int i = x; i > 0; i = pre[i])
    {
        l[++c1] = i - pre[i];
        if (c1 == k)
            break;
    }
    for (int i = x; i <= n; i = nxt[i])
    {
        r[++c2] = nxt[i] - i;
        if (c2 == k)
            break;
    }
    ll res = 0;
    for (int i = 1; i <= c1; i++)
    {
        if (k - i + 1 <= c2)
        {
            res += 1LL * l[i] * r[k - i + 1];
        }
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            pos[x] = i;
            pre[i] = i - 1;
            nxt[i] = i + 1;
        }
        pre[0] = 0;
        nxt[n + 1] = n + 1;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += cal(pos[i]) * i;
            del(pos[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}