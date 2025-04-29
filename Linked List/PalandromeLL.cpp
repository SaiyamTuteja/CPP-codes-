#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
class List
{
public:
    bool arrayPlandrome(vector<int> &arr)
    {
        int s = 0;
        int e = arr.size() - 1;
        while (s <= e)
        {
            if (arr[s] != arr[e])
            {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    void palandrome(Node *head)
    {
        vector<int> arr;
        Node *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        bool ispalandrome = arrayPlandrome(arr);
        if (ispalandrome)
        {
            cout << "Yes its a palandrome Linked list ";
        }
        else
        {
            cout << "NO its no a palandrome :";
        }
        return;
    }

    Node *craeteNode(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = NULL;
        newNode->data = data;
        return newNode;
    }
    Node *insertAtBegining(Node *head, int data)
    {
        Node *newNode = craeteNode(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    void print(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    List l;
    Node *head = nullptr;

    head = l.insertAtBegining(head, 10);
    head = l.insertAtBegining(head, 20);
    head = l.insertAtBegining(head, 30);
    head = l.insertAtBegining(head, 30);
    head = l.insertAtBegining(head, 20);
    head = l.insertAtBegining(head, 60);
    l.print(head);
    l.palandrome(head);

    return 0;
}