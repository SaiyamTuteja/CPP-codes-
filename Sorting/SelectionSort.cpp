#include <bits/stdc++.h>
using namespace std;
// what if i select the min element and put it to its right position ->>Ascending order
// what if i select the max element and put it to its right position ->>Descending order
void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }
        // swap the min element with the element at the current position
        if (min_ind != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_ind];
            arr[min_ind] = temp;
        }
    }
}

void print(int arr[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[6] = {20, 12, 10, 15, 2, 7};
    cout << "Before Sorted array:";
    print(arr, 6);
    selectionSort(arr, 6);
    cout << "After Sorted array:";
    print(arr, 6);
}