
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
class CircularLl
{
public:
    Node *head = nullptr;
    Node *tail = nullptr;

    void insertionAThead(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    void deltionAtHead()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            temp->next = nullptr;
            delete temp;
        }
    }
    void DeletionAtTail()
    {
        if (head == nullptr)
        {
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *prev = head;
            Node *temp = tail;
            while (prev->next != tail)
            {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = nullptr;
            delete temp;
        }
    }
    void printcll()
    {
        if (head == nullptr)
        {
            cout << "There is no node avalable ";
            return;
        }
        Node *temp = head;
        cout << temp->data << " ->";
        temp = head->next;
        while (temp != head)
        {
            cout << temp->data << " ->";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

int main()
{
    CircularLl cl;
    cl.insertionAThead(12);
    cl.insertionAThead(22);
    cl.insertionAThead(32);
    cl.insertionAThead(42);
    cout << "Before Deletion: ";
    cl.printcll();
    cout << "After Deletion: ";
    // cl.deltionAtHead();
    cl.DeletionAtTail();
    cl.printcll();
}
