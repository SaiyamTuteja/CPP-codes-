#include "bits/stdc++.h"
using namespace std;

void linear_search(vector<int> &arr, int key)
{
    bool found = false; // Flag to check if the key is found
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at index: " << i << endl;
            found = true;
            break; // Stop searching after finding the element
        }
    }
    if (!found)
    {
        cout << "Element not found" << endl;
    }
}
int binary_search(vector<int> &arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
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

            swap(arr[i], arr[j]);
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
    int left = low;
    int right = mid + 1;
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
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}
int gcd(int a, int b)
{
    if ((a == 1 || b == 1) || a == b)
    {
        // base case
        return a;
    }
    else if (a > b)
    {
        return gcd(a - b, b);
    }
    else
    {
        return gcd(a, b - a);
    }
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
int fabonica(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    else
    {
        return fabonica(n - 1) + fabonica(n - 2);
    }
}
int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
void print_name(int n, string s)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        cout << s << " ";
        print_name(n - 1, s);
    }
}
int print_no(int n)
{
    if (n == 0)
    {
        return n;
    }
    else
    {
        print_no(n - 1);
        cout << n << " ";
    }
}
void even_no(int n)
{
    if (n > 20)
    {
        return;
    }
    else
    {
        cout << n << " ";
        even_no(n + 2);
    }
}
int sumofN(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        // cout << n << " ";
        return n + sumofN(n - 1);
    }
}
int Decimal_to_binary(int n)
{
    if (n == 0)
    {
        return n;
    }
    else
    {
        Decimal_to_binary(n / 2);
        cout << n % 2 << " ";
    }
}
int Binary_to_decimal(int n, int power = 0)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        int lastdigit = n % 10;
        return (lastdigit * pow(2, power)) + Binary_to_decimal(n / 10, power + 1);
    }
}
void even_odd(vector<int> &arr)
{
    vector<int> temp;
    vector<int> temp2;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0)
        {
            temp.push_back(arr[i]);
            // cout << arr[i] << " even ";
        }
        else
        {
            temp2.push_back(arr[i]);
            // cout << arr[i] << " odd ";
        }
    }
    // eveen no
    cout << "even no:";
    for (int i = 0; i <= temp.size() - 1; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
    // odd no
    cout << "odd no:";
    for (int i = 0; i <= temp2.size() - 1; i++)
    {
        cout << temp2[i] << " ";
    }
}
int reverseArr(vector<int> &arr, int i, int j)
{

    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int decimalToBinary(int &n)
{
    vector<int> arr;
    int i = 0;
    while (n > 0)
    {
        arr.push_back(n % 2);
        n = n / 2;
        i++;
    }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        cout << arr[i];
    }
    cout << endl;
}
int Min_MAx(vector<int> &arr)
{
    int minVal = arr[0];
    int maxVal = arr[0];
    for (int i = 1; i <= arr.size() - 1; i++)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    cout << "MIN VALUE IS :" << minVal << endl;
    cout << "MAX VALUE IS :" << maxVal;
}

int main()
{
    // vector<int> arr = {1, 2, 45, 6, 3, 7, 8, 9, 0};
    // int low = 0;
    // int high = arr.size() - 1;
    // merge_sort(arr, low, high);
    // Quick_sort(arr, low, high);
    // print(arr);

    // int a = 7;
    // int b = 24;
    // cout << gcd(a, b);

    // int a = 7;
    // int b = 21;
    // cout << lcm(a, b);

    // int n = 5;
    // int i = 0;
    // while (i <= n)
    // {
    //     cout << fabonica(i) << " ";
    //     i++;
    // }

    // cout << factorial(5);
    // print_name(10, "saiyam");
    // print_no(10);
    // int p = (7 * 21) / __gcd(7, 21);
    // cout << p;

    // even_no(2);
    // int n = 5;
    // cout << "sum of " << n << " natural no is " << sumofN(n);

    // Decimal_to_binary(10);
    // cout << Binary_to_decimal(1010);
    // vector<int> arr = {1, 2, 3, 4, 5};
    // for (int i = arr.size() - 1; i >= 0; i--)
    // {
    //     cout << arr[i] << " ";
    // }

    // vector<int> arr = {12, 13, 34, 3, 56, 4, 576, 8, 2, 4};
    // even_odd(arr);

    // vector<int> arr = {12, 13, 34, 3, 56, 4, 576, 8, 2, 4};
    // reverseArr(arr, 0, arr.size() - 1);

    // vector<int> arr = {12, 13, 34, 3, 56, 4, 576, 8, 2, 4};
    // int n = 10;
    // decimalToBinary(n);

    // vector<int> arr = {12, 13, 34, 3, 56, 4, 576, 8, 2, 4};
    // Min_MAx(arr);

    vector<int>arr={1,234,46,5,75,869,7};
    

    return 0;
}
