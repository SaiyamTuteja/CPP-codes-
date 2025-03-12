#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << "Size of the queue is " << q.size() << endl;
    cout << "Front element of the queue is " << q.front() << endl;
    cout << "Back element of the queue is " << q.back() << endl;
    cout << "Queue elements are" << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << "Size of the queue is " << q.size() << endl;
    return 0;
}