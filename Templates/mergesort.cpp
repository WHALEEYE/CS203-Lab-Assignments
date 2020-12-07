#include <iostream>
using namespace std;
void mergeSort(int seq[], int tseq[], int idx[], int tidx[], int l, int r);
void combine(int seq[], int tseq[], int idx[], int tidx[], int l, int mid, int r);
int mid, s, k, p;
long long power(int n);

int main()
{
    int n, p, q;
    scanf("%d%d%d", &n, &p, &q);
    q = q > n ? n : q;
    long long maxA = 0, atksum = 0, temp;
    int gap[n], idx[n], tidx[n], tgap[n], hp, atk, hps[n], atks[n], bidx;
    bool en = true;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &hp, &atk);
        atksum += atk;
        hps[i] = hp;
        atks[i] = atk;
        gap[i] = hp - atk;
        tgap[i] = hp - atk;
        idx[i] = i;
        tidx[i] = i;
    }
    if (q == 0)
    {
        printf("%lld", atksum);
        return 0;
    }
    mergeSort(gap, tgap, idx, tidx, 0, n - 1);
    if (p != 0)
    {
        bidx = n - q;
        for (int i = n - 1; i > n - q; i--)
        {
            atksum += gap[i];
            if (gap[i - 1] < 0)
            {
                bidx = i - 1;
                en = false;
                break;
            }
        }
        for (int i = 0; i <= bidx; i++)
        {
            temp = atksum + hps[idx[i]] * power(p) - atks[idx[i]];
            maxA = temp > maxA ? temp : maxA;
        }
        if (en)
        {
            atksum += gap[bidx];
        }
        for (int i = bidx + 1; i < n; i++)
        {
            temp = atksum - gap[i] + hps[idx[i]] * power(p) - atks[idx[i]];
            maxA = temp > maxA ? temp : maxA;
        }
        printf("%lld", maxA);
        return 0;
    }
    else
    {
        for (int i = n - 1; i >= n - q && gap[i] > 0; i--)
        {
            atksum += gap[i];
        }
        printf("%lld", atksum);
        return 0;
    }
}

long long power(int n)
{
    long long a = 1;
    for (int i = 0; i < n; i++)
    {
        a = a * 2;
    }
    return a;
}

void mergeSort(int seq[], int tseq[], int idx[], int tidx[], int l, int r)
{
    if (l < r)
    {
        mid = (l + r) / 2;
        mergeSort(seq, tseq, idx, tidx, l, mid);
        mid = (l + r) / 2;
        mergeSort(seq, tseq, idx, tidx, mid + 1, r);
        mid = (l + r) / 2;
        combine(seq, tseq, idx, tidx, l, mid, r);
    }
}

void combine(int seq[], int tseq[], int idx[], int tidx[], int l, int mid, int r)
{
    s = l, k = mid + 1, p = l;
    while (true)
    {
        if (s <= mid && k <= r)
        {
            if (seq[s] > seq[k])
            {
                tseq[p] = seq[k];
                tidx[p] = idx[k];
                k++;
            }
            else
            {
                tseq[p] = seq[s];
                tidx[p] = idx[s];
                s++;
            }
        }
        else if (s == mid + 1)
        {
            tseq[p] = seq[k];
            tidx[p] = idx[k];
            k++;
        }
        else if (k == r + 1)
        {
            tseq[p] = seq[s];
            tidx[p] = idx[s];
            s++;
        }
        if (s == mid + 1 && k == r + 1)
        {
            for (int i = l; i <= r; i++)
            {
                seq[i] = tseq[i];
                idx[i] = tidx[i];
            }
            break;
        }
        p++;
    }
}
