#include <iostream>
using namespace std;
void split(int pre[], int in[], int inid[], int l, int r, int root);
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int tree[n + 1][2], pre[n], inid[n + 1], idx, in[n];
        for (int i = 0; i <= n; i++)
        {
            tree[i][0] = tree[i][1] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> pre[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> idx;
            inid[idx] = i;
            in[i] = idx;
        }
        split(pre, in, inid, 0, n - 1, 0);
        cout << "\n";
    }
    return 0;
}

void split(int pre[], int in[], int inid[], int l, int r, int root)
{
    if (l == r)
    {
        cout << in[l] << " ";
        return;
    }
    else if (l > r)
    {
        return;
    }
    split(pre, in, inid, l, inid[pre[root]] - 1, root + 1);
    split(pre, in, inid, inid[pre[root]] + 1, r, root + inid[pre[root]] + 1 - l);
    cout << pre[root] << " ";
}