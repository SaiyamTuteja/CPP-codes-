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

class List
{
    Node *head;

public:
    List()
    {
        head = nullptr;
    }
    void push_front(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void MiddlePosLL()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->data << " ";
        return;
    }
};
int main()
{
    List l;
    l.push_front(10);
    l.push_front(20);
    l.push_front(30);
    l.push_front(40);
    l.push_front(50);
    l.push_front(60);
    l.push_front(70);
    cout << "Linked List is :";
    l.print();
    cout << "Middle Element is :";
    l.MiddlePosLL();
}