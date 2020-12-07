#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int lgh;
    string s;
    cin >> s;
    lgh = s.length();
    int k = 0, pi[lgh], i = 1;
    pi[0] = 0;
    while (i < lgh)
    {
        if (s[k] == s[i])
        {
            k++;
            pi[i] = k;
            i++;
        }
        else if (k == 0)
        {
            pi[i] = 0;
            i++;
        }
        else
        {
            k = pi[k - 1];
        }
    }
    for (int i = 0; i < lgh; i++)
    {
        cout << pi[i] << "\n";
    }
    return 0;
}