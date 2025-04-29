#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        next = nullptr;
        this->data = data;
    }
};
class List
{
    Node *head;

public:
    List()
    {
        head = nullptr;
    }
    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NUll\n";
    }
    void push_front(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return;
    }
    void push_back(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            push_front(data);
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;

        return;
    }
    void ReverseLL()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head=prev;
        return;
    }
};

int main()
{
    List l;
    l.push_back(10);
    l.push_front(20);
    l.push_front(30);
    l.push_front(40);
    l.push_front(50);
    cout << "before reverse a linked list\n";
    l.print();
    cout << "after the reverse of the ll\n";
    l.ReverseLL();
    l.print();
    return 0;
}