<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
// Fibonacci Series in Cpp: In case of fibonacci series, next number is the sum of previous two numbers for
//  example 0, 1, 1, 2, 3, 5, 8, 13, 21 etc. The first two numbers of fibonacci series are 0 and 1.
int main()
{
    int n = 0;
    int n1 = 1;
    int n2;
    for (int i = 0; i < 10; i++)
    {
        cout << n << endl;
        n2 = n + n1;
        n = n1;
        n1 = n2;
    }
    return 0;
=======
#include <bits/stdc++.h>
using namespace std;
// Fibonacci Series in Cpp: In case of fibonacci series, next number is the sum of previous two numbers for
//  example 0, 1, 1, 2, 3, 5, 8, 13, 21 etc. The first two numbers of fibonacci series are 0 and 1.
int main()
{
    int n = 0;
    int n1 = 1;
    int n2;
    for (int i = 0; i < 10; i++)
    {
        cout << n << endl;
        n2 = n + n1;
        n = n1;
        n1 = n2;
    }
    return 0;
>>>>>>> 2f841c65c092149f4646fbb1a55eb16c5428688a
}