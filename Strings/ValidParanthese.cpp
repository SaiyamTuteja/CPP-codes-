
#include <bits/stdc++.h>
#include <string>
using namespace std;
int isValidParanthese(string &s)
{
    stack<char> st;
    for (char a : s)
    {
        if (a == '(')
        {
            st.push(a);
        }
        else if (a == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                st.push(a);
            }
        }
    }
    return st.size();
}
int validParanthese(string &s)
{

    vector<char> ans(s.length());
    int countRight = 0;
    int countLeft = 0;
    for (auto c : s)
    {
        if (c == '(')
        {
            countRight++;
        }
        else if (c == ')')
        {
            if (countRight > 0)
            {
                countRight--;
            }
            else
            {
                countLeft++;
            }
        }
    }

    return countRight + countLeft;
}
int main()
{

    string s = "(()()))(())";
    int ans = validParanthese(s);
    cout << "Using the Noraml Approach : " << ans << " ";
    cout << endl;c:\Users\saiya\OneDrive\Documents\College work\Python\notebooks\RemoveOccurenceFromString.cpp c:\Users\saiya\OneDrive\Documents\College work\Python\notebooks\RemoveOccurenceFromString.exe c:\Users\saiya\OneDrive\Documents\College work\Python\notebooks\ValidPlandrome.cpp c:\Users\saiya\OneDrive\Documents\College work\Python\notebooks\ValidPlandrome.exe
    int ans2 = isValidParanthese(s);
    cout << "Using the stack Approach : " << ans2 << " ";
    return 0;
}