#include <iostream>
using namespace std;
// Amstrong Number in Cpp: A positive number is called an Armstrong number of order n if    abcd... = a^n + b^n + c^n + d^n + ...
// Example: 153 = 1*1*1 + 5*5*5 + 3*3*3 // 153 is an Armstrong number.
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int sum = 0;
    int originalN = n;
    while (n > 0)
    {
        int lastDigit = n % 10;
        sum += lastDigit * lastDigit * lastDigit;
        n = n / 10;
    }
    if (sum == originalN)
    {
        cout << originalN << " is an Armstrong number.";
    }
    else
    {
        cout << originalN << " is not an Armstrong number.";
    }
    return 0;
}