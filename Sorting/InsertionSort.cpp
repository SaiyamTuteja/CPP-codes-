#include <bits/stdc++.h>
using namespace std;
void inertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {12, 21, 31, 2};
    int n = 4;

    printf("Before Array: ");
    printArr(arr, n);

    inertionSort(arr, n);


    printf("AFter Sort");
    printArr(arr, n);

    return 0;
}