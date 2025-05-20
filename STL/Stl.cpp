#include <bits/stdc++.h>
using namespace std;
// all about the STL in C++ Standard Template Library  (STL)
// STL is a collection of C++ libraries that provides a set of generic, reusable components for creating algorithms, data structures, and other useful utilities.
// STL has four components
// 1. Algorithms
// 2. Containers
// 3. Functions
// 4. Iterators
// Algorithms: STL algorithms operate on containers and provide means to perform initialization, sorting, searching, and transforming operations on the elements of containers.
// Containers: Containers or container classes store objects and data. There are in total seven standard “first-class” container classes and three container adaptor classes and only seven header files that provide access to these containers or container adaptors.
// Functions: Functions are used to perform operations on the elements of containers.
// Iterators: Iterators are used to point at the memory addresses of STL containers.
// STL is a library of generic classes and functions that can be used with any type of data.
// STL is created by Alexander Stepanov and Meng Lee at HP labs.
// STL is based on the concept of generic programming.
// STL is based on the concept of containers. A container is a holder object that stores a collection of other objects (its elements).
// STL is based on the concept of iterators. An iterator is an object that points to an element in the container.
void Stacks()
{
    // Stack is a LIFO (Last In First Out) data structure
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.top() << endl;
    s.pop();
    // Output: 5
    cout << s.top() << endl;
    // Output: 4
    cout << s.size() << endl;
    // Output: 4
    cout << s.empty() << endl;
    // Output: 0
}
void Queues()
{
    // Queue is a FIFO (First In First Out) data structure
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.front() << endl;
    q.pop();
    cout << q.back() << endl;
    // Output: 5
    cout << q.front() << endl;
    // Output: 2
    cout << q.size() << endl;
    // Output: 4
    cout << q.empty() << endl;
    // Output: 0
}
void Sets()
{
    // Set is an unordered collection of unique elements
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    for (auto i : s)
    {
        cout << i << " ";
    }
    // Output: 1 2 3 4 5
    s.erase(3);
    for (auto i : s)
    {
        cout << i << " ";
    }
    // Output: 1 2 4 5
    cout << s.count(4) << endl;
    // Output: 1
    cout << s.count(3) << endl;
    // Output: 0
    cout << s.size() << endl;
    // Output: 4
    cout << s.empty() << endl;
    // Output: 0
}
void pairs()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;
    pair<int, pair<int, int>> p1 = {1, {2, 3}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;
    pair<int, int> arr[] = {{1, 2}, {2, 3}, {4, 5}};
    cout << arr[0].first << " " << arr[0].second << endl;
}
void vectors()
{
    vector<int> v = {1, 2, 3, 4, 5};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<int> v1(5, 10);
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    vector<int> v2(5);
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;
    vector<int> v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(3);
    v3.push_back(4);
    v3.push_back(5);
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " ";
    }
    cout << endl;
    v3.pop_back();
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " ";
    }
    cout << endl;
}
void Llist()
{
    list<int> l;
    l.push_back(10);
    l.push_back(20);
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "Front of list is  : " << l.front() << " ";

    cout << "Back of list is  : " << l.back() << " ";
}

int main()
{
    // pairs();
    // vectors();
    // Stacks();
    // Queues();
    // Sets();
    Llist();
    return 0;
}
