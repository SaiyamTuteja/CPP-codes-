#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};
struct Node *CreateNode(struct Node *root, int data)
{
    struct Node *right = NULL;
    int data;
    struct Node *left = NULL;
    return root;
}
void preOrder(struct Node *rt)
{
    printf("%d \n", rt->data);
    postOrder(rt->left);
    postOrder(rt->right);
}
void postOrder(struct Node *rt)
{

    postOrder(rt->left);
    postOrder(rt->right);
    printf("%d \n", rt->data);
}
void inOrder(struct Node *rt)
{
    postOrder(rt->left);
    printf("%d \n", rt->data);
    postOrder(rt->right);
}
int main()
{
    struct Node *root = NULL;
    inOrder(root);
    preOrder(root);
    postOrder(root);
    return 0;
}