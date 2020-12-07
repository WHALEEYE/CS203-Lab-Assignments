#include <iostream>
using namespace std;
void quickSort(long long seq[], int index[], int l, int r);
long long pivot;
int idx, i, j;

int main()
{
    int n, x1, x2, k, b;
    scanf("%d%d%d", &n, &x1, &x2);
    long long seq1[n], seq2[n];
    int index[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &k, &b);
        seq1[i] = (long long)k * x1 + b;
        seq2[i] = (long long)k * x2 + b;
        index[i] = i;
    }
    quickSort(seq1, index, 0, n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        if (seq2[index[i]] > seq2[index[i + 1]])
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}

void quickSort(long long seq[], int index[], int l, int r)
{
    if (l < r)
    {
        i = l;
        j = r;
        pivot = seq[l];
        idx = index[l];
        while (i < j)
        {
            while (i < j && seq[j] >= pivot)
            {
                j--;
            }
            if (i < j)
            {
                seq[i] = seq[j];
                index[i++] = index[j];
            }
            while (i < j && seq[i] < pivot)
            {
                i++;
            }
            if (i < j)
            {
                seq[j] = seq[i];
                index[j--] = index[i];
            }
        }
        index[i] = idx;
        seq[i] = pivot;
        quickSort(seq, index, l, i - 1);
        quickSort(seq, index, i + 1, r);
    }
}