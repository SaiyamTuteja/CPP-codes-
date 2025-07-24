#include <bits/stdc++.h>
using namespace std;
bool isPlandrome(string &s)
{
    int start = 0;
    int end = s.length() - 1;
    while (start < end)
    {
        if (!isalnum(s[start]))
        {
            start++;
            continue;
        }
        if (!isalnum(s[end]))
        {
            end--;
            continue;
        }
        if (tolower(s[start]) != tolower(s[end]))
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }

    return true;
}
int main()
{
    string str;
    cout << "enter the string for cheking the palandrome :";
    getline(cin, str);
    bool ans = isPlandrome(str);
    cout << ans << " ";
    return 0;
}