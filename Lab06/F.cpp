#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char table[26];
    string ipt;
    for (int i = 0; i < 26; i++)
    {
        cin >> table[i];
    }
    cin >> ipt;
    int lgh = ipt.length();
    int pi[lgh], j = (lgh + 1) / 2, k = 0;
    while (j < lgh)
    {
        if (ipt[k] == table[ipt[j] - 97])
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
    cout << lgh - pi[lgh - 1];
    return 0;
}