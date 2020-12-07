#include <iostream>
using namespace std;

int main()
{
    int count, a, b, n;
    cin >> count;
    int out[count];
    for (int i = 0; i < count; i++)
    {
        cin >> a >> b >> n;
        switch (n % 3)
        {
        case 0:
            out[i] = a;
            break;
        case 1:
            out[i] = b;
            break;
        default:
            out[i] = a ^ b;
            break;
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << out[i] << endl;
    }
    return 0;
}