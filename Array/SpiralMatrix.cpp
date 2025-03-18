#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> SpiralMatrix(vector<vector<int>> &mat, int n, int m)
{
    vector<int> ans; 

    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while (top <= bottom && left <= right)
    {
        // Traverse from left to right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(mat[top][i]);
        }
        top++;
        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(mat[i][right]);
        }
        right--;
        // Traverse from right to left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        // Traverse from bottom to top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    int n = 4, m = 4;
    vector<vector<int>> mat{{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}};
    vector<int> ans = SpiralMatrix(mat, n, m);

    // Print the resulting vector
    for (int i = 0; i < ans.size(); i++) 
    {
        cout << ans[i] << " ";
    }
    return 0;
}
