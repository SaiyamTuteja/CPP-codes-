#include <bits/stdc++.h>
using namespace std;
// swap the adjusent elements of array if needed
void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[6] = {20, 12, 10, 15, 2, 7};
    cout << "Before Sorted:";
    print(arr, 6);
    BubbleSort(arr, 6);
    cout << "After Sorted:";
    print(arr, 6);
}