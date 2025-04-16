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
    printf("NULL");
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
    while (temp != NULL)
    {
        
    }
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

    return 0;
}