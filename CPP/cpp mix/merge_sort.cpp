// #include <bits/stdc++.h>

// using namespace std;
// void merge(vector<int> &arr, int low, int mid, int high)
// {
//     vector<int> temp;
//     int right = mid + 1;
//     int left = low;
//     while (left <= mid && right <= high)
//     {
//         if (arr[left] <= arr[right])
//         {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else
//         {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//     while (left <= mid)
//     {
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while (right <= high)
//     {

//         temp.push_back(arr[right]);
//         right++;
//     }
//     for (int i = low; i <= high; i++)
//     {
//         arr[i] = temp[i - low];
//     }
// }
// void merge_sort(vector<int> &arr, int low, int high)
// {
//     if (low >= high)
//     {
//         return;
//     }
//     int mid = low + (high - low) / 2;

//     merge_sort(arr, low, mid);
//     merge_sort(arr, mid + 1, high);
//     merge(arr, low, mid, high);
// }
// void print(const vector<int> &arr)
// {
//     for (int num : arr)
//     {
//         cout << num << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     vector<int> arr = {3, 2, 1, 1, 3};
//     int low = 0;
//     int high = arr.size() - 1; // Fixed to the last index of the array
//     merge_sort(arr, low, high);
//     print(arr);
//     return 0;
// }
//------------------------------Quick Sort--------------------------------------------

#include <bits/stdc++.h>
using namespace std;
int Partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void QuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = Partition(arr, low, high);
        QuickSort(arr, low, pIndex - 1);
        QuickSort(arr, pIndex + 1, high);
    }
}
void Print(const vector<int> &arr)
{
    for (auto num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}
int main()
{

    vector<int> arr = {2, 4, 3, 2, 1, 2, 1213, 43, 435};
    int low = 0;
    int high = arr.size() - 1;
    QuickSort(arr, low, high);
    Print(arr);
    return 0;
}