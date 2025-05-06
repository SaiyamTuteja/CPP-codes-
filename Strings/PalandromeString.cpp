#include <bits/stdc++.h>
using namespace std;

void validPalindrome(string str)
{
    string rev = str;              
    reverse(rev.begin(), rev.end()); 
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
