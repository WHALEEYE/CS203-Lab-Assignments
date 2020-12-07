#include <iostream>
using namespace std;

int main()
{
    long long n, n1;
    int t, s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long tst = 1;
        int md = 0;
        cin >> n >> s;
        n1 = n;
        while (tst <= n)
        {
            md++;
            tst *= 10;
        }
        int dgtsum = 0;
        for (int j = 0; j < md + 1; j++)
        {
            dgtsum += n1 / tst;
            n1 -= ((n1 / tst) * tst);
            if ((n1 != 0 && dgtsum > s - 1) || (n1 == 0 && dgtsum > s))
            {
                n = (((n / (tst * 10)) + 1) * tst * 10) - n;
                break;
            }
            else if (n1 == 0 && dgtsum <= s)
            {
                n = 0;
                break;
            }
            tst /= 10;
        }
        cout << n << endl;
    }
    return 0;
}