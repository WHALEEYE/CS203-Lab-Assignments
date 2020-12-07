#include <iostream>
using namespace std;
int moreSteps(int storey);

int main()
{
    int cases, storey;
    cin >> cases;
    int out[cases];
    for (int i = 0; i < cases; i++)
    {
        cin >> storey;
        out[i] = moreSteps(storey) - 1;
    }
    for (int i = 0; i < cases; i++)
    {
        cout << out[i] << endl;
    }
    return 0;
}

int moreSteps(int storey)
{
    if (storey < 17)
    {
        int tot = 1;
        for (int i = 0; i < storey; i++)
        {
            tot *= 3;
        }
        return tot % 1000000007;
    }
    else
    {
        int tot = moreSteps(16);
        for (int i = 16; i < storey; i++)
        {
            tot = (((2 * tot) % 1000000007) + tot) % 1000000007;
        }
        return tot;
    }
}