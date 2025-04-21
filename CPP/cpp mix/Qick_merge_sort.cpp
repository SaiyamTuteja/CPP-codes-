#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int low, int high)
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
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void Quick_sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        Quick_sort(arr, low, pIndex - 1);
        Quick_sort(arr, pIndex + 1, high);
    }
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int left = low;
    vector<int> temp;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void merge_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void print(const vector<int> &arr)
{
    for (auto nums : arr)
    {
        cout << nums << " ";
    }
    cout << endl;
}

// int main()
// {
//     vector<int> arr = {32, 24, 353, 64, 7474, 74, 7664, 344, 12};
//     int low = 0;
//     int high = arr.size() - 1;
//     // merge_sort(arr, low, high);
//     Quick_sort(arr, low, high);
//     print(arr);
//     return 0;
// }

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int fabbonica(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fabbonica(n - 1) + fabbonica(n - 2);
    }
}

int gcd(int a, int b)
{
    if ((a == 1 || b == 1) || a == b)
    {
        return a;
    }
    // else if (a == b)
    // {
    //     return b;
    // }
    else if (a > b)
        return gcd(a - b, b);

    else
    {
        return gcd(a, b - a);
    }
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int lcm_without_gcd(int a, int b)
{
    int max = (a > b) ? a : b;
    while (true)
    {
        if (max % a == 0 && max % b == 0)
        {
            return max;
        }
        max++;
    }
}

int main()
{
    // factorial
    // int n;
    // cout << "enter the value of N : ";
    // cin >> n;
    // cout << factorial(n);

    // Fabbonica Series
    // int i = 0;
    // while (i < n)
    // {
    //     cout << fabbonica(i) << " ";
    //     i++;
    // }

    // GCD CALL
    // int a = 7;
    // int b = 21;
    // cout << gcd(a, b);

    // predefined function GCD
    // int a = 7;
    // int b = 7;
    // cout << __gcd(a, b);

    // lcm
    // int a = 3;
    // int b = 21;
    // cout << lcm(a, b);

    // lcm Without GCD
    // int a = 7;
    // int b = 21;
    // cout << lcm_without_gcd(a, b);

    return 0;
}
