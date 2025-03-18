#include <bits/stdc++.h>
using namespace std;

void LeaderArray(int arr[], int size)
{
    int maxFromRight = arr[size - 1]; // The last element is always a leader
    cout << maxFromRight << endl;

    // Traverse the array from right to left
    for (int i = size - 2; i >= 0; i--)
    {
        if (arr[i] > maxFromRight)
        {
            maxFromRight = arr[i];
            cout << maxFromRight << endl;
        }
    }
}

int main()
{
    int arr[4] = {4, 7, 1, 0};
    int size = 4;

    LeaderArray(arr, size); // Call function to print leaders

    return 0;
}
