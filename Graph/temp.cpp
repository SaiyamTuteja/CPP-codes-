#include <bits/stdc++.h>
using namespace std;
int p(int i)
{
    if (i > 28)
    {
        return 0;
    }
    else
    {
        int x = p(i + 2);65
        cout << x << endl;
        return x;
    }
}
int main()
{

    int i = 1;

    p(i);
    return 0;
}