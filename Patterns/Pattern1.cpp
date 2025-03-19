#include <bits/stdc++.h>
using namespace std;
/*
Pattern 1
******
******
******
******
******
******

Pattern 2
*
**
***
****
*****
******

Pattern 3

******
*****
****
***
**
*

Pattern 4
      ******
     ******
    ******
   ******
  ******

Pattern 5

 ******
  *****
   ****
    ***
     **
      *

Pattern 6

 ******
  ******
   ******
    ******
     ******
      ******

      */
void Pattern1(int n)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void Pattern2(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void Pattern3(int n)
{
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void Pattern4(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void Pattern5(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        for (int j = i; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void Pattern6(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void Pattern7(int n)
{
    
}
int main()
{
    int n;
    cout << "Enter the n :";
    cin >> n;
    // Pattern1(n);
    // Pattern2(n);
    // Pattern3(n);
    // Pattern4(n);
    // Pattern5(n);
    // Pattern6(n);
    // Pattern7(n);
    return 0;
}
