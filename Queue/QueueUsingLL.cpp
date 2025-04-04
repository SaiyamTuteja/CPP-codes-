#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        val = data;
        next = NULL;
    }
};
class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }
    void enQueue(int data)
    {
        if (empty())
        {
            cout << "Queue is full";
        }
        else
        {
           
        }
    }
    void dequeue()
    {
    }
    int front()
    {
        return
    }
    bool empty()
    {
    }
};
int main()
{
    return 0;
}