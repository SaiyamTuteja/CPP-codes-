#include <bits/stdc++.h>
using namespace std;
// O(n2)
int maxSumBrute(vector<int> &arr, int n)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// O(n)
int KadaneAlgo(vector<int> &arr, int n)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxSum = max(sum, maxSum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {-2, -3, -8, -7, -1, -2, -3};
    int n = arr.size();
    cout << "Brute Force Max Sum: " << maxSumBrute(arr, n) << endl;
    cout << "Kadane's Algorithm Max Sum: " << KadaneAlgo(arr, n) << endl;
    return 0;
}