#include <stdio.h>
#include <stdlib.h>
#define size 10
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void pushStart(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void pushEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = *head;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
    {

        temp = temp->next;
    }
    temp->next = newNode;
}

void Push()
{
}

void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main()
{
    struct Node *head = NULL;
    int data = 30;
    int data1 = 10;
    int data2 = 20;
    pushStart(&head, data1);
    pushStart(&head, data2);
    pushEnd(&head, data);
    print(head);
    // print(head);
    // print(head);
    return 0;
}