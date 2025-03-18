#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

bool SearchIn2DArray(int arr[100][100], int n, int m, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == target)
            {
                return true; // Target found
            }
        }
    }
    return false; // Target not found
}

int main()
{
    int n = 3, m = 4;
    int arr[100][100] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    int target = 12;

    if (SearchIn2DArray(arr, n, m, target))
    {
        cout << "Element found!" << endl;
    }
    else
    {
        cout << "Element not found!" << endl;
    }

    return 0;
}
