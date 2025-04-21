#include <bits/stdc++.h>
using namespace std;

void count_prime(vector<int> &arr)
{
    int primeCount = 0;
    for (int num : arr)
    {
        if (num < 2)
            continue; // Ignore numbers less than 2
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            primeCount++;
    }
    cout << "Number of prime numbers: " << primeCount << endl;
}
void count_even_odd(vector<int> &arr)
{
    int even_count = 0;
    int odd_count = 0;
    for (int i = 0; i <= arr.size() - 1; i++)
    {

        if (arr[i] % 2 == 0)
        {
            even_count++;
        }
        else
        {
            odd_count++;
        }
    }
    cout << "The Count of the even no in an array is :" << even_count << endl;
    cout << "The Count of the odd no in an array is :" << odd_count;
}
void even_odd(vector<int> &arr)
{
    vector<int> even;
    vector<int> odd;

    for (int i = 0; i <= arr.size() - 1; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even.push_back(arr[i]);
        }

        else
        {
            odd.push_back(arr[i]);
        }
    }
    cout << "even  no is :";
    for (int nums : even)
    {
        cout << nums << " ";
    }
    cout << endl;
    cout << "odd  no is :";
    for (int num2 : odd)
    {
        cout << num2 << " ";
    }
    cout << endl;
}
void Decimal_to_binary(vector<int> &arr)
{
    int n = arr.size() - 1;
    int reminder = 0;

    for (int i = 0; i <= n; i++)
    {
        int num = arr[i];
        vector<int> binary;
        while (num > 0)
        {
            binary.push_back(num % 2);
            num = num / 2;
        }
        reverse(binary.begin(), binary.end());
        for (int bit : binary)
        {
            cout << bit;
        }
        cout << " ";
    }
}
void concat(vector<int> &arr1, vector<int> &arr2)
{
    // arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    // for (int i = 0; i < arr1.size(); i++)
    // {
    //     cout << arr1[i] << " ";
    // }
    // cout << endl;

    // or

    vector<int> arr3;
    int n = arr1.size();
    int m = arr2.size();
    if (n == m)
    {
        for (int i = 0; i < n; i++)
        {
            arr3.push_back(arr1[i]);
        }
        for (int j = 0; j < m; j++)
        {
            arr3.push_back(arr2[j]);
        }
    }
    for (int i = 0; i < arr3.size(); i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
}
bool serach_element(vector<int> &arr, int element)
{
    int flag = 0;
    int n = arr.size() - 1;
    for (int i = 0; i <= n; i++)
    {
        if (element == arr[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "elemnt found ";
    }
    else
    {
        cout << "elemnt not found ";
    }
}
void Second_min_element(vector<int> &arr)
{
    int first_min = INT_MAX;
    int second_min = INT_MAX;
    int n = arr.size() - 1;
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] < first_min)
        {
            second_min = first_min;
            first_min = arr[i];
        }
        else if (arr[i] < second_min && arr[i] != first_min)
        {
            second_min = arr[i];
        }
    }
    if (second_min == INT_MAX)
    {
        cout << "NO element is present here :";
    }
    else
    {
        cout << "Second minimum element is :" << second_min;
    }
}
void second_max_element(vector<int> &arr)
{
    int firstMax = INT_MIN;
    int secondMax = INT_MIN;
    int n = arr.size() - 1;
    for (int i = 0; i <= n; i++)
    {
        if (firstMax < arr[i])
        {
            secondMax = firstMax;
            firstMax = arr[i];
        }
        else if (secondMax < arr[i] && arr[i] != firstMax)
        {
            secondMax = arr[i];
        }
    }
    if (secondMax == INT_MIN)
    {
        cout << "NO element found at the largest in an array :";
    }
    cout << "second largest element is :" << secondMax;
}
void three_max_element(vector<int> &arr)
{
    int fisrt_max = INT_MIN;
    int Second_max = INT_MIN;
    int third_max = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > fisrt_max)
        {
            third_max = Second_max;
            Second_max = fisrt_max;
            fisrt_max = arr[i];
        }
        else if (arr[i] > Second_max && arr[i] != fisrt_max)
        {
            third_max = Second_max;
            Second_max = arr[i];
        }
        else if (arr[i] > third_max && arr[i] != fisrt_max && arr[i] != Second_max)
        {
            third_max = arr[i];
        }
    }
    cout << "first maximum element is :" << fisrt_max << endl;
    cout << "second maximum element is: " << Second_max << endl;
    cout << "third largest element is: " << third_max << endl;
}
void min(vector<int> &arr)
{
    int first = INT_MAX;
    int n = arr.size() - 1;
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] < first)
        {
            first = arr[i];
        }
    }
    cout << "Minimum element is :" << first;

    // // or

    // sort(arr.begin(), arr.end());
    // cout << "Minimum elememnt is : " << arr[0];
}
void max(vector<int> &arr)
{
    int fisrt = INT_MIN;
    int n = arr.size() - 1;
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] > fisrt)
        {
            fisrt = arr[i];
        }
    }
    cout << "Maximum element in an array is :" << fisrt;

    // or

    // int n = arr.size() - 1;
    // int maxi = arr[0];
    // for (int i = 0; i <= n; i++)
    // {
    //     if (maxi < arr[i])
    //     {
    //         maxi = arr[i];
    //     }
    // }
    // cout << "MAXIMUM IN AN ARRAY IS : " << maxi << " ";
}
void Sum_of_Two_array(vector<int> &arr, vector<int> &arr2)
{
    int sum1 = 0;
    int sum2 = 0;
    int temp = 0;
    for (int i = 0; i <= 8; i++)
    {
        sum1 += arr[i];
        sum2 += arr2[i];
        temp = sum1 + sum2;
    }
    cout << temp << " ";
}
void sum_of_array(vector<int> &arr, int n)
{
    int sum = 0;

    for (int i = 0; i <= n; i++)
    {
        sum += arr[i];
    }
    cout << sum << " ";
}
void reverse_array(vector<int> &arr, int n)
{
    int start = 0;
    int end = n - 1;
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
    vector<int> arr = {1, 34, 5, 6, 10, 0, 4, 9};
    // int n = 8;
    // vector<int> arr2 = {2, 1, 2, 3, 5, 4, 6, 5};
    // cout << "orignal array :";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // reverse_array(arr, n);
    // cout << "Reversed array: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // sum_of_array(arr, n);
    // Sum_of_Two_array(arr, arr2);

    // max(arr);
    // min(arr);
    // three_max_element(arr);
    // second_max_element(arr);
    // Second_min_element(arr);
    // serach_element(arr, 34);

    // vector<int> arr1 = {1, 2, 3, 4};
    // vector<int> arr2 = {7, 6, 8, 9};
    // concat(arr1, arr2);
    // Decimal_to_binary(arr);
    // even_odd(arr);
    // count_even_odd(arr);
    // count_prime(arr);
}