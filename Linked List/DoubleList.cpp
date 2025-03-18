#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *next, Node *prev)
    {
        data = data;
        next = next;
        prev = prev;
    }

public:
    Node(int data)
    {
        data = data;
        next = nullptr;
        prev = nullptr;
    }
};
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = nullptr;
    }
    void printll()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }
};
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = new Node(v[0]);
    Node *temp = head;

    printll(head);
}