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
// Output
// Size of the queue is 5
// Front element of the queue is 1
// Back element of the queue is 5
// Queue elements are
// 1 2 3 4 5
// Size of the queue is 0
// In the above code, we have used the queue STL to implement a queue. The queue STL is a container adapter that gives the programmer the functionality of a queue. The queue STL is a FIFO (First In First Out) data structure. The queue STL is a part of the C++ Standard Template Library (STL). The queue STL is implemented using the deque STL. The queue STL provides the following member functions:
//
// push(x): Adds an element x to the back of the queue. 
// pop(): Removes the front element of the queue.
// front(): Returns the front element of the queue.
// back(): Returns the back element of the queue.
// size(): Returns the number of elements in the queue.
// empty(): Returns true if the queue is empty, otherwise false.
// The queue STL is a very useful data structure that is used in many applications. The queue STL is very efficient and easy to use. The queue STL is a very powerful tool that can be used to solve many problems. The queue STL is a very important part of the C++ Standard Template Library (STL).
