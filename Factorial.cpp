#include <bits/stdc++.h>
using namespace std;
// factorial of a number  n! = n*(n-1)*(n-2)*...*1  = n*(n-1)!  = n*(n-1)*(n-2)! = n*(n-1)*(n-2)*(n-3)! = ... = n*(n-1)*(n-2)*...*1
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    cout << fact << endl;
    return 0;
}