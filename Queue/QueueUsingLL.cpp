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
        Node *newNode = new Node(data);

        if (empty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void dequeue()
    {
        if (empty())
        {
            cout << "LL is empty";
        }

        Node *temp = head;
        head = head->next;
        delete (temp);
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