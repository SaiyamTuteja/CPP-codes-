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
    void push_head(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void push_mid(int data, int pos)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        int count = 1;
        Node *temp = head;

        while (temp != nullptr || count < pos)
        {
            if (count == pos)
            {
                newNode->next = temp;
                temp->next = newNode;

                return;
            }
        }
    }
    void push_tail(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = nullptr;
    }
};
void removeElementsAbove10(vector<int> &nums, int value)
{
}
int main()
{
    vector<int> numbers = {1, 5, 12, 8, 20, 3};
}
