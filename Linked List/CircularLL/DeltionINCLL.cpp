
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
    void 
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
};

int main()
{
}
