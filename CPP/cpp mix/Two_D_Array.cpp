#include <bits/stdc++.h>
using namespace std;
void print(int a[100][100], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void input(int a[100][100], int row, int column)
{
    cout << "Enter the element:" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> a[i][j];
        }
    }
}
void transpose(int a[100][100], int b[100][100], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            b[j][i] = a[i][j];
        }
    }
}
bool isPresent(int a[100][100], int target, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (a[i][j] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}
void Dignal_sum(int a[100][100], int row)
{
    int sum_dignal = 0;

    for (int i = 0; i < row; i++)
    {
        sum_dignal += a[i][i];
    }
    cout << "Sum Dignal is :" << sum_dignal << endl;
}
void Row_sum(int a[100][100], int row, int column)
{

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < column; j++)
        {
            sum += a[i][j];
        }
        cout << "Row " << i << " sum is : " << sum << endl;
    }
    // cout << "Total  SUM is :" << sum;
    cout << endl;
}
void ColumnSum(int a[100][100], int row, int column)
{
    for (int j = 0; j < column; j++)
    {
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += a[i][j];
        }
        cout << "Column " << j << " sum is : " << sum << endl;
    }
}
void Oppsoite_dignal(int a[100][100], int row)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        sum += a[i][row - i - 1];
    }
    cout << "Oppsoite Dignal sum is " << sum;
}
int largest_row_Sum(int a[100][100], int row, int column)
{
    int Maxi = INT_MIN;
    int RowIndex = -1;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;

        for (int j = 0; j < column; j++)
        {
            sum += a[i][j];
        }
        if (sum > Maxi)
        {
            Maxi = sum;
            RowIndex = i;
        }
    }
    cout << "The maximum sum is :" << Maxi;
    return RowIndex;
}
int main()
{
    int row;
    cout << "How Many Rows" << endl;
    cin >> row;
    int column;
    cout << "How Many Column" << endl;
    cin >> column;
    int a[100][100];
    input(a, row, column);
    print(a, row, column);

    // Dignal_sum(a, row, column);
    Row_sum(a, row, column);
    ColumnSum(a, row, column);
    Dignal_sum(a, row);
    Oppsoite_dignal(a, row);
    cout << "Maximum row is at Index:" << largest_row_Sum(a, row, column);
    // int target;
    // cout << " Enter the element that you have to find out :";
    // cin >> target;
    // if (isPresent(a, target, row, column) == true)
    // {
    //     cout << "Element Found";
    // }
    // else
    // {
    //     cout << "Element Not found ";
    // }

    // input(a, row, column);
}