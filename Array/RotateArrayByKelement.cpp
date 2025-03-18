#include <bits/stdc++.h>
using namespace std;
void Reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int temp[k];

    // Brute force approach

    // for (int i = 0; i < k; i++)
    // {
    //     temp[i] = arr[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = arr[i + k];
    // }
    // for (int i = 0; i < k; i++)
    // {
    //     arr[n - k + i] = temp[i];
    // }

    // or we can use this code

    // Better approach

    // for (int i = 0; i < k; i++)
    // {
    //     arr[n + i] = arr[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = arr[i + k];
    // }

    // Reverse approach
    Reverse(arr, 0, k - 1);
    Reverse(arr, k, n - 1);
    Reverse(arr, 0, n - 1);

    cout << "After Roration by " << k << " element :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}