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
    void Serach(int key)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Key found" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Key not found" << endl;
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
                temp = temp->next;
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
    void push_position(int data, int pos)
    {
        int curr_pos = 1;
        Node *newNode = new Node(data);
        Node *temp = head;
        if (pos == 1)
        {
            push_front(data);
            return;
        }
        while (temp != nullptr && curr_pos < pos - 1)
        {
            temp = temp->next;
            curr_pos++;
        }
        if (temp == nullptr)
        {
            cout << "OUt of bound ";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }
};
int main()
{
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.print_list();
    cout << "Searching the files in the list" << endl;
    l.Serach(3);
    l.Serach(6);
    l.pop_front();
    l.print_list();
    l.pop_back();
    l.print_list();
    l.push_front(100);
    l.print_list();
    l.push_position(12, 3);
    l.print_list();
    return 0;
}