#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int value)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = value;
    return newNode;
}
void printll(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct Node *insertAtHead(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    newNode->next = head;
    head = newNode;
    return head;
}
struct Node *insertAtTail(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    if (head == NULL)
    {
        return newNode;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
struct Node *insertAtPos(struct Node *head, int data, int pos)
{
    struct Node *newNode = createNode(data);
    if (pos == 1)
    {

        return insertAtHead(head, data);
    }
    struct Node *temp = head;
    int count = 1;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        return insertAtTail(head, data);
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void search(struct Node *head, int key)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Elemnt found\n");
        }
        temp = temp->next;
    }
}

struct Node *delAtValue(struct Node *head, int key)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head != NULL && head->data == key)
    {
        head = head->next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found in the list.\n", key);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}
int main()
{
    struct Node *head = NULL;
    int data;
    for (int i = 1; i < 5; i++)
    {
        printf("Enter the data  at : %d", i);
        scanf("%d", &data);
        head = insertAtHead(head, data);
    }
    printll(head);
    head = insertAtTail(head, 100);
    printll(head);

    head = insertAtPos(head, 200, 3);
    printll(head);

    search(head, 40);

    head = delAtValue(head, 40);
    printll(head);

    return 0;
}