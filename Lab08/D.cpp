#include <iostream>
using namespace std;
typedef long long ll;

ll func_a(ll x)
{
    ll tmp = x, sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return (tmp + sum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t, k, s;
    cin >> t >> k >> s;
    ll last_ans = s, sod, hp[k], temp, data, min;
    int cur, rear = 0;
    // for (int i = 0; i < k; i++)
    // {
    //     hp[i] = 100000000000000000LL;
    // }
    for (int i = 0; i < t / 100; i++)
    {
        temp = i * 100 + 1 + last_ans;
        data = func_a(temp);
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (rear >= k)
                {
                    rear--;
                    hp[0] = hp[rear];
                    cur = 0;
                    while (true)
                    {
                        if (2 * cur + 2 >= rear)
                        {
                            min = 2 * cur + 1;
                        }
                        else
                        {
                            min = hp[2 * cur + 1] > hp[2 * cur + 2] ? (2 * cur + 2) : (2 * cur + 1);
                        }
                        if (hp[cur] > hp[min])
                        {
                            temp = hp[cur];
                            hp[cur] = hp[min];
                            hp[min] = temp;
                            cur = min;
                        }
                        else
                        {
                            break;
                        }
                        if (2 * cur + 1 >= rear)
                        {
                            break;
                        }
                    }
                }
                cur = rear;
                hp[rear++] = data;
                while (cur > 0)
                {
                    if (hp[cur] < hp[(cur - 1) / 2])
                    {
                        temp = hp[cur];
                        hp[cur] = hp[(cur - 1) / 2];
                        hp[(cur - 1) / 2] = temp;
                        cur = (cur - 1) / 2;
                    }
                    else
                    {
                        break;
                    }
                }
                data += 2;
            }
            data -= 9;
        }
    }
    return 0;
}