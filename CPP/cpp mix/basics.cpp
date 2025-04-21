#include <iostream>
using namespace std;
void countNo(int n)
{
    int count = 0;
    while (n > 0)
    {
        int lastDigit = n % 10;
        cout << lastDigit << " ";
        count++;
        n = n / 10;
    }
    cout << "count is : " << count << endl;
}
int reverse(int n)
{
    int rev = 0;
    while (n > 0)
    {
        int lastDigit = n % 10;
        n = n / 10;
        rev = (rev * 10) + lastDigit;
    }
    cout << "Reverse NO is :" << rev << endl;
}
void palandrome(int n)
{
    int rev = 0;
    int orignal = n;
    while (n > 0)
    {
        int lastDigit = n % 10;
        n = n / 10;
        rev = (rev * 10) + lastDigit;
    }
    if (orignal == rev)
    {
        cout << "The no is Palandrome :";
    }
    else
    {
        cout << " The no is not Palandrome";
    }
}
void amstrong(int n)
{
    int orignal = n;
    int sum = 0;
    while (n > 0)
    {
        int ld = n % 10;
        sum = sum + (ld * ld * ld);
        n = n / 10;
    }
    if (sum == orignal)
    {
        cout << "Its an AMSTRONG no :";
    }
    else
    {
        cout << " NOt an amstrong NO:";
    }
}
void Divisiable(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if ((n % i) == 0)
        {
            cout << i << " ";
        }
    }
}
int main()
{
    int n;
    cout << "enter the digits: ";
    cin >> n;
    // countNo(n);
    // reverse(n);
    // palandrome(n);
    // amstrong(n);
    Divisiable(n);
}