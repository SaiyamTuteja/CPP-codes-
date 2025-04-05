#include <bits/stdc++.h>
#include <queue>
using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node(int val)
//     {
//         data = val;
//         next = NULL;
//     }
// };
// class Queue
// {
//     Node *head;
//     Node *tail;

// public:
//     Queue()
//     {
//         head = tail = NULL;
//     }
//     void enQueue(int data)
//     {
//         Node *newNode = new Node(data);

//         if (empty())
//         {
//             head = tail = newNode;
//         }
//         else
//         {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }
//     void dequeue()
//     {
//         if (empty())
//         {
//             cout << "LL is empty";
//             return;
//         }

//         Node *temp = head;
//         head = head->next;
//         delete temp;
//     }
//     int front()
//     {
//         if (empty())
//         {
//             cout << "LL is empty";
//             return -1;
//         }
//         return head->data;
//     }
//     bool empty()
//     {
//         return head == NULL;
//     }
// };
// int main()
// {
//     Queue q;
//     q.enQueue(10);
//     q.enQueue(20);
//     q.enQueue(30);
//     q.enQueue(40);
//     while (!q.empty())
//     {
//         cout << q.front() << " ";
//         q.dequeue();
//     }
//     cout << endl;
//     return 0;
// }

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}