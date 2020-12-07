#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t, n, k, ini, powi;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        ini = k + 1;
        powi = k;
        while (ini < n)
        {
            powi *= k;
            ini += powi;
        }
        ini -= powi;
        powi /= k;
        cout << (n - ini) + powi - ((n - ini + k - 1) / k) << endl;
    }
    return 0;
}