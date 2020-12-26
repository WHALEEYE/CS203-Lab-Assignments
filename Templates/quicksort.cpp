#include <iostream>
using namespace std;
long long pivot;
int idx, i, j;

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