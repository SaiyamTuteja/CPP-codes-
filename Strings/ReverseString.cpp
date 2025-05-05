#include <bits/stdc++.h>

using namespace std;
int main()
{

    string str = "this is Saiyam";
    cout << "Before Reverse : " << str << endl;
    // using two pointer approch
    int start = 0;
    int end = str.size() - 1;
    while (start < end)
    {
        swap(str[start++], str[end--]);
    }
    cout << "After Reverse: " << str << endl;

    // using cpp stl

    reverse(str.begin(), str.end());
    cout << str;

    return 0;
}