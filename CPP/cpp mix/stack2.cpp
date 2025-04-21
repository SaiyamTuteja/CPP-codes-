// #include <bits/stdc++.h>
// using namespace std;
// class Stack
// {
// public:
//     int top = -1;
//     int st[10];
//     Stack()
//     {

//         stack<int> st;
//     }
//     void push(int n)
//     {
//         if (top >= 10)
//         {
//             cout << "overflow accured";
//         }
//         top = top + 1;
//         st[top] = n;
//         cout << "Element inserted suceesfully" << endl;
//     }
//     void pop()
//     {
//         if (top == -1)
//         {
//             cout << "underflow exits";
//         }
//         top = top - 1;
//         cout << "Element deleted suceesfully" << endl;
//     }
//     void tos()
//     {
//         if (top == -1)
//         {
//             cout << "underflow exits";
//         }
//         cout << "Top of stack is :" << st[top] << endl;
//     }
//     void size()
//     {
//         cout << "Size of the stack is :" << top + 1 << endl;
//     }
// };

// int main()
// {
//     Stack s1;
//     s1.push(10);
//     s1.push(20);
//     s1.push(30);
//     s1.tos();
//     s1.pop();
//     s1.tos();
//     s1.size();
// }
#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int curSize = 0;
    int start = 0;
    int end = 0;
    int size = 10;
    int qu[10];
    Queue()
    {
        queue<int> qu;
    }
    void push(int n)
    {
        if (curSize == qu[10])
        {
            cout << "Element out of bound:";
        }
        if (curSize == 1)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % size;
        }
        qu[end] = n;
        curSize += 1;
    }
    void top()
    {
    }
    void pop()
    {
    }
    void size()
    {
    }
};
int main()
{
}