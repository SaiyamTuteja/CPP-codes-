// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int arr[] = {2, 32, 42, 12, 3, 42, 24};
//     int arr2[] = {1, 2, 3, 41, 13, 21};
//     int n1 = sizeof(arr) / sizeof(arr[0]);
//     int n2 = sizeof(arr2) / sizeof(arr2[0]);
//     cout << medianArr(arr, n1) << endl;
//     cout << medianArr(arr2, n2) << endl;
// }

// String Anagram

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> Freq(vector<int> arr)
{
    vector<int> ans;
    int n = arr.size();
    unordered_map<int, int> um;
    for (auto i : arr)
    {
        um[i]++;
        ans.push_back(um[i]);
    }
    return ans;
}

bool palandrome(string s1)
{
    for (char &c : s1)
    {
        c = tolower((unsigned char)c);
    }
    int left = 0;
    int right = s1.size() - 1;
    while (left <= right)
    {
        if (s1[left] != s1[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void reverse(string s1)
{
    // reverse(s1.begin(), s1.end());
    // cout << s1;
    // or

    // string rev = "";
    // for (char ch = s1.length(); ch >= 0; ch--)
    // {
    //     cout << s1[ch] << " ";
    // }
    // cout << endl;

    // or

    // stack<char> st1;
    // for (auto ch : s1)
    // {
    //     st1.push(ch);
    // }
    // while (!st1.empty())
    // {
    //     cout << st1.top() << " ";
    //     st1.pop();
    // }
    // cout << endl;
}

string ReplaceString(string s1)
{
    string vowels = "aeiouAEIOU";
    for (auto &c : s1)
    {
        if (vowels.find(c) != string::npos)
        {
            c = '*';
        }
    }
    return s1;
}

int sumEven(vector<int> arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

int medianArr(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    sort(arr, arr + n);
    if (n % 2 != 0)
    {
        return arr[n / 2];
    }
    else
    {
        int median1 = arr[(n / 2) - 1];
        int median2 = arr[n / 2];
        return (median1 + median2) / 2;
    }
    return 0;
}

int factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    return n * factorial(n - 1);
}

int fabonaciSeries(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fabonaciSeries(n - 1) + fabonaciSeries(n - 2);
}

bool leapYear(int year)
{
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
    // if (year % 400 == 0)
    // {
    //     return true;
    // }
    // if (year % 100 == 0)
    // {
    //     return false;
    // }
    // if (year % 4 == 0)
    // {
    //     return true;
    // }
    // return false;
}

bool anagram(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

int main()
{

    // vector<int> arr = {1, 2, 1, 3, 2, 1};
    // vector<int> result = Freq(arr);
    // for (int x : result)
    //     cout << x << " ";
    // cout << endl;

    // if (palandrome("RaceCar"))
    // {
    //     cout << "yes its palandrome ";
    // }
    // else
    // {
    //     cout << "Not a palandrome";
    // }

    // reverse("saiyam");

    // cout << "the Replaced string is :" << ReplaceString("saiyam") << endl;

    // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // cout << "the sum is :" << sumEven(arr, arr.size()) << endl;

    // for (int i = 0; i < 6; i++)
    // {
    //     cout << factorial(i) << endl;
    // }
    // cout << factorial(5) << endl;

    // for (int i = 0; i < 6; i++)
    // {
    //     cout << fabonaciSeries(i) << endl;
    // }
    // cout << fabonaciSeries(7) << endl;

    // int year = 2016;
    // if (leapYear(year))
    // {
    //     cout << "The year is Leap Year" << endl;
    // }
    // else
    // {
    //     cout << "the year is not leap year" << endl;
    // }

    // string s1 = "saiyam";
    // string s2 = "yamsai";
    // if (anagram(s1, s2))
    // {
    //     cout << "the string is anagram " << endl;
    // }
    // else
    // {
    //     cout << " string is not an anagram";
    // }
    return 0;
}