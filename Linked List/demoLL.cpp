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
        next = NULL;
    }
};
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }
    void push_back(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void print_list()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp=temp->next;

            }
            delete tail;
            tail = temp;
            tail->next = NULL;
            
        }
    }
    void push_front(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
};
int main()
{
}