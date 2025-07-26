#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void PushStart(int data, struct node *&head)
{
    struct node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void PushEnd(int data, struct node *&head)
{
    struct node *newNode = createNode(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    struct node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void PushATPos(int data, struct node *&head, int pos)
{
    if (pos == 1)
    {
        PushStart(data, head);
        return;
    }

    struct node *temp = head;
    int currPos = 1;

    while (temp != NULL && currPos < pos - 1)
    {
        temp = temp->next;
        currPos++;
    }

    if (temp == nullptr)
    {
        cout << "Position out of bounds\n";
        return;
    }

    struct node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void Display(struct node *head)
{
    struct node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    struct node *head = NULL;

    PushStart(10, head);
    Display(head);

    PushStart(20, head);
    Display(head);

    PushEnd(0, head);
    Display(head);

    PushATPos(30, head, 2); // Insert 30 at position 2
    Display(head);

    return 0;
}
