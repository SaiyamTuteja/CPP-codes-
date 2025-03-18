// Two Pair sum problem
// Given an array of integers, and a number ‘sum’, find the number of pairs of integers in the array whose sum is equal to ‘sum’.
// Example:
// Input  :  arr[] = {1, 5, 7, -1}, sum = 6
// Output :  2
// Pairs with sum 6 are (1, 5) and (7, -1)
// Input  :  arr[] = {1, 5, 7, -1, 5}, sum = 6
// Output :  3
// Pairs with sum 6 are (1, 5), (7, -1) & (1, 5)
// Input  :  arr[] = {1, 1, 1, 1}, sum = 2
// Output :  6
// There are 3! pairs with sum 2.
// Input  :  arr[] = {10, 12, 10, 15, -1, 7, 6,
#include <bits/stdc++.h>
using namespace std;
void TwoPairSum(int arr[], int n, int target)
{
    sort(arr, arr + n);
    int j = n - 1;
    int sum = 0;
    int i = 0;
    while (i <= j)
    {
        sum = arr[i] + arr[j];
        if (sum == target)
        {
            cout << "Pair found: " << target << " = " << arr[i] << " + " << arr[j] << " at index " << i << " and " << j << endl;
            break;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int arr[] = {2, 6, 5, 8, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int Target = 14;
    TwoPairSum(arr, n, Target);
    return 0;
}