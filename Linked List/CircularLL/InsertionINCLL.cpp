#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = nullptr;
    }
    Node *createNode(int data)
    {
        Node *newNode = new Node(data);
        data = data;
        newNode->next = nullptr;
        return newNode;
    }

    void insertHead(int val)
    {
        Node *newNode = createNode(val);
        // no Node
        if (head == nullptr)
        {
            tail = head = newNode;
            tail->next = head;
        }
        else
        { // 1 or more then 2 nodes
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    void printll()
    {
        if (head == nullptr)
        {
            return;
        }
        cout << head->data << " ->";
        Node *temp = head->next;
        while (temp != head)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
    void insertAtTail(int data)
    {
        Node *newNode = createNode(data);
        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }
};

int main()
{

    CircularList cll;
    // cll.insertHead(11);
    // cll.insertHead(12);
    // cll.insertHead(13);
    // cll.insertHead(14);
    cll.insertAtTail(10);
    cll.insertAtTail(20);
    cll.insertAtTail(30);
    cll.insertAtTail(40);
    cll.insertAtTail(50);
    cll.printll();
    return 0;
}