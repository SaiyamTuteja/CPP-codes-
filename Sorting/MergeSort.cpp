#include <bits/stdc++.h>
using namespace std;
void merge(int low, int mid, int high, vector<int> &arr)
{
    int len1 = low + mid;
    int len2 = high - mid + 1;

    vector<int> temp1(len1), temp2(len2);
    while (len1 <= mid && len2 <= high)
    {
        
    }
    while (len1 <= mid)
    {
    }
    while (len2 <= high)
    {
    }
}
void mergeSort(int low, int high, vector<int> &arr)
{
    int mid = low + (high - low) / 2;
    if (low >= high)
    {
        return;
    }
    mergeSort(low, mid, arr);
    mergeSort(mid + 1, high, arr);
    merge(low, mid, high, arr);
}
int main()
{
}