// Appear once and other two times
#include <bits/stdc++.h>
using namespace std;

void Once_Unique(int arr[], int n)
{
    // int res = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     res = res ^ arr[i];
    // }
    // cout << res;

    // or we can use this code
    //     int temp = 0;
    //     sort(arr, arr + n);
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (arr[i] == arr[i + 1])
    //         {
    //             i++;
    //         }
    //         else if (arr[i] != arr[i + 1])
    //         {
    //             temp = arr[i];
    //             break;
    //         }
    //     }
    //     cout << temp;
    // }
}
int main()
{
    int arr[] = {1, 2, 3, 2, 3, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    Once_Unique(arr, n);
    return 0;
}