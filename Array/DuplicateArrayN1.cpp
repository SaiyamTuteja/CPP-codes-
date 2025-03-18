#include <bits/stdc++.h>
using namespace std;
void Duplicate(int arr[], int n)
{
    int Fsum = 0, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        Fsum += i;
    }
    for (int i = 0; i < n + 1; i++)
    {
        sum += arr[i];
    }
    int result = sum - Fsum;
    cout << "Result is :" << result;
}
int main()
{
    int arr[] = {1, 3, 4, 2, 2};
    int n = 5;
    Duplicate(arr, n);
}