#include <iostream>
using namespace std;
int pivot, i, j;
void mergeSort(long long seq[], long long tseq[], int l, int r);
void combine(long long seq[], long long tseq[], int l, int mid, int r);
int mid, s, k, p;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int ipt[n];
    long long sum = 0, seq[n - 1], tseq[n - 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ipt[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        sum += ipt[i + 1];
        seq[i] = tseq[i] = sum;
    }
    sum += ipt[0];
    mergeSort(seq, tseq, 0, n - 2);
    for (int i = n - 2; i > n - m - 1; i--)
    {
        sum += seq[i];
    }
    printf("%lld", sum);
    return 0;
}

void mergeSort(long long seq[], long long tseq[], int l, int r)
{
    if (l < r)
    {
        mid = (l + r) / 2;
        mergeSort(seq, tseq, l, mid);
        mid = (l + r) / 2;
        mergeSort(seq, tseq, mid + 1, r);
        mid = (l + r) / 2;
        combine(seq, tseq, l, mid, r);
    }
}

void combine(long long seq[], long long tseq[], int l, int mid, int r)
{
    s = l, k = mid + 1, p = l;
    while (true)
    {
        if (s <= mid && k <= r)
        {
            if (seq[s] > seq[k])
            {
                tseq[p] = seq[k];
                k++;
            }
            else
            {
                tseq[p] = seq[s];
                s++;
            }
        }
        else if (s == mid + 1)
        {
            tseq[p] = seq[k];
            k++;
        }
        else if (k == r + 1)
        {
            tseq[p] = seq[s];
            s++;
        }
        if (s == mid + 1 && k == r + 1)
        {
            for (int i = l; i <= r; i++)
            {
                seq[i] = tseq[i];
            }
            break;
        }
        p++;
    }
}
