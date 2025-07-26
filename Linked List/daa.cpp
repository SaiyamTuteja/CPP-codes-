#include <bits/stdc++.h>
using namespace std;
void sortTwoUnsortedArray(vector<int> &arr1,int n, vector<int> &arr2, int m)
{
    arr1.resize(n + m);
    int i = n - 1;
    int j = m - 1;
    int k = n + m - 1;
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] >= arr2[j])
        {
            arr1[k--] = arr1[i--];
        }
        else
        {
            arr1[k--] = arr2[j--];
        }
    }
    while (j >= 0)
    {
        arr1[k--] = arr2[j--];
    }
}
int main()
{
    vector<int> arr1 = {2, 4, 5, 14}; 
    vector<int> arr2 = {3, 5, 7, 12};
    sortTwoUnsortedArray(arr1,4, arr2,4);
    for (auto it : arr1)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}