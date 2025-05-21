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
    // Create an empty list of integers
    list<int> l;

    // Check if the list is empty initially
    cout << "List is Empty or not : " << l.empty() << endl;

    // Insert elements at the end of the list
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);

    // Insert element at the end using emplace_back (constructs in-place)
    l.emplace_back(02); // 02 is treated as 2

    // Insert element at the beginning using emplace_front
    l.emplace_front(01); // 01 is treated as 1

    // Check if the list is still empty
    cout << "List is Empty or not : " << l.empty() << endl;

    // Print all elements in the list
    cout << "The list is : ";
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Print the first and last elements of the list
    cout << "Front of list is  : " << l.front() << endl;
    cout << "Back of list is  : " << l.back() << "\n";

    // Print the size of the list
    cout << "Size of the List is : " << l.size() << endl;

    // Reverse the list and print it
    cout << "Reverse of list is : ";
    l.reverse();
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Print front and back after reversing
    cout << "The front element is : " << l.front() << endl;
    cout << "The back element is : " << l.back() << endl;

    // Create a second list and swap it with the original list
    list<int> l2;
    l.swap(l2);

    // After swap, l2 contains the elements from l
    cout << "L2 list after swapping from l1 : ";
    for (auto it = l2.begin(); it != l2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // l is now empty after the swap with l2
    cout << "L1 list after swapping from l2 : ";
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Clear all elements from l (though it's already empty after the swap)
    l.clear();

    // Print l after clearing (no output expected)
    cout << "After clearing the elements : ";
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
}
void PriorityQueue()
{
    priority_queue<int> pq;
    pq.emplace(10);
    pq.emplace(20);
    pq.emplace(50);
    pq.emplace(1000);
    pq.emplace(230);
    pq.push(300);
    cout << " Max Heap is : ";
    while (!pq.empty())
    {
        int a = pq.top();
        cout << a << " ";
        pq.pop();
    }
    cout << endl;
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.emplace(10);
    pq2.emplace(20);
    pq2.emplace(50);
    pq2.emplace(1000);
    pq2.emplace(230);
    pq2.push(300);
    pq2.push(100);
    cout << " Min Heap is : ";
    while (!pq2.empty())
    {
        int a = pq2.top();
        cout << a << " ";
        pq2.pop();
    }
    cout << endl;

    string str = "SaiyamTuteja";
    map<char, int> freq;
    for (char c : str)
    {
        freq[c]++;
    }

    priority_queue<pair<int, char>> pqchar;
    for (auto &p : freq)
    {
        pqchar.push({p.second, p.first});
    }
    cout << "Char frequency of the string is in the descending order are : ";
    while (!pqchar.empty())
    {
        cout << pqchar.top().second << " is " << pqchar.top().first << endl;
        pqchar.pop();
    }

        cout << endl;
}
int main()
{
    // pairs();
    // vectors();
    // Stacks();
    // Queues();
    // Sets();
    // Llist();
    PriorityQueue();
    return 0;
}
