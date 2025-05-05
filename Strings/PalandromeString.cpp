#include <bits/stdc++.h>
using namespace std;

void validPalindrome(string str)
{
    string rev = str;                // Make a copy
    reverse(rev.begin(), rev.end()); // Reverse the copy
    if (str == rev)
    {
        cout << "Yes, it's a palindrome." << endl;
    }
    else
    {
        cout << "No, it's not a palindrome." << endl;
    }
}

int main()
{
    string str = "madam";
    validPalindrome(str);

    return 0;
}
