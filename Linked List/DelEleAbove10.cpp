#include <iostream>
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

    void push_tail(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void push_mid(int data, int pos)
    {
        Node *newNode = new Node(data);
        if (pos <= 1 || head == nullptr)
        {
            push_head(data);
            return;
        }

        Node *temp = head;
        int count = 1;
        while (temp != nullptr && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr)
        {
            push_tail(data);
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void removeElementsAbove10()
    {
        // Remove from head
        while (head != nullptr && head->data > 10)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        Node *curr = head;
        Node *prev = nullptr;

        while (curr != nullptr)
        {
            if (curr->data > 10)
            {
                Node *temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ✅ main() outside the class
int main()
{
    List myList;
    myList.push_tail(5);
    myList.push_tail(12);
    myList.push_tail(7);
    myList.push_tail(15);
    myList.push_tail(3);

    cout << "Original list: ";
    myList.print();

    myList.removeElementsAbove10();

    cout << "After removing elements > 10: ";
    myList.print();

    return 0;
}
// Output:
// Original list: 5 -> 12 -> 7 -> 15 -> 3 -> NULL
// After removing elements > 10: 5 -> 7 -> 3 -> NULL
// This program demonstrates the removal of elements greater than 10 from a linked list.
// This program defines a linked list and provides functionality to remove elements greater than 10.
// This program defines a linked list and provides
// functionality to print the list and remove specific elements.
// functionality to add new elements to the list.
// to remove elements greater than 10 from the list.
// to add new elements to the list.
