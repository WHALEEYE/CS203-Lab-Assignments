#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str1;
    int n, lgh, j, k, lgh0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str1;
        lgh = lgh0 = str1.length();
        int pi[lgh];
        pi[0] = 0;
        k = 0;
        j = 1;
        while (j < lgh)
        {
            if (str1[k] == str1[j])
            {
                k++;
                pi[j] = k;
                j++;
            }
            else if (k == 0)
            {
                pi[j] = 0;
                j++;
            }
            else
            {
                k = pi[k - 1];
            }
        }
        while (!pi[lgh - 1] || lgh0 % (lgh0 - pi[lgh - 1]))
        {
            lgh0++;
            pi[lgh - 1]++;
        }
        cout << lgh0 - lgh << "\n";
    }
    return 0;
}