#include <bits/stdc++.h>
using namespace std;
void Lenear_search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element  found at index" << i;
            return;
        }
    }
    cout << "element not found ";
}
void Binary_Search(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (key == arr[mid])
        {
            cout << "element found " << endl;
            return;
        }
        else if (arr[mid] >= key)
        {
            end = mid - 1;
        }
        else if (arr[mid] <= key)
        {
            start = mid + 1;
        }
    }
    cout << "Element not found";
    return;
}
void Bubble_Sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // int small_index = i;
        for (int j = 1; j < n - 1; j++)
        {
            if (arr[j] >= arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int Small_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[Small_index])
            {
                Small_index = j;
            }
        }
        swap(arr[i], arr[Small_index]);
    }
}
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}
void printReverse(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// print array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ";
}

int main()
{
    int n = 5;
    int arr[] = {1, 22, 3, 7, 6};
    // int key = 222;
    // Lenear_search(arr, n, key);
    // Binary_Search(arr, n, key);
    // Bubble_Sort(arr, n);
    // selection_sort(arr, n);
    insertion_sort(arr, n);
    cout
        << "Array after sorted is -:  ";
    print(arr, n);
    cout << endl
         << "Reverse Array is :  ";
    printReverse(arr, n);

    return 0;
}