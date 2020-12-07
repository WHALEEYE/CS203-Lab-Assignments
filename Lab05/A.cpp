#include <iostream>
#include <string>
using namespace std;

int main()
{

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int stack[30010], top = 0;
        string ipt;
        char brac;
        cin >> ipt;
        bool pair = true;
        for (int j = 0; j < n; j++)
        {
            brac = ipt[j];
            switch (brac)
            {
            case '{':
            case '[':
            case '(':
                stack[top] = brac;
                top++;
                break;
            case '}':
                top--;
                if (top < 0)
                {
                    pair = false;
                    break;
                }
                if (stack[top] != '{')
                {
                    pair = false;
                    break;
                }
                break;
            case ']':
                top--;
                if (top < 0)
                {
                    pair = false;
                    break;
                }
                if (stack[top] != '[')
                {
                    pair = false;
                    break;
                }
                break;
            case ')':
                top--;
                if (top < 0)
                {
                    pair = false;
                    break;
                }
                if (stack[top] != '(')
                {
                    pair = false;
                    break;
                }
                break;
            }
            if (!pair)
            {
                break;
            }
        }
        if (pair && top == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}