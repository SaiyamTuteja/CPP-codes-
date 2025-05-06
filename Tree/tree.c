#include <stdio.h>
#include <stdlib.h>
void inorder()
{
}
void preorder()
{
}
void postorder()
{
}
struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}
struct Node *insertNode(struct Node *root, int data)
{
    struct Node *newNode = createNode(data);
    if(root==NULL){
        newNode->data=data;
        newNode->left;
    }
}
int main()
{
    struct Node *root = NULL;
    inorder();
    preorder();
    postorder();
    return 0;
}