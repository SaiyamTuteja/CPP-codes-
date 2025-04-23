#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
struct Node *CreateNode(int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};
    return newNode;
}

struct Node *insertNode(struct Node *root, int data)
{
    struct Node *newNode = CreateNode(data);
    if (root == nullptr)
        return new Node{data, nullptr, nullptr};

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
        return root;
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}
void preOrder(struct Node *rt)
{
    if (rt == NULL)
        return;
    printf("%d \t", rt->data);
    preOrder(rt->left);
    preOrder(rt->right);
}
void postOrder(struct Node *rt)
{
    if (rt == NULL)
        return;
    postOrder(rt->left);
    postOrder(rt->right);
    printf("%d \t", rt->data);
}
void inOrder(struct Node *rt)
{
    if (rt == NULL)
        return;
    inOrder(rt->left);
    printf("%d \t", rt->data);
    inOrder(rt->right);
}
int main()
{
    Node *root = NULL;
    int values[] = {10, 50, 30, 40, 80, 60, 70, 20, 90, 100};

    for (int val : values)
        root = insertNode(root, val);

    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << "\nPreorder Traversal: ";
    preOrder(root);
    cout << "\nPostorder Traversal: ";
    postOrder(root);
    cout << endl;
    cout << "program ended ";
    return 0;
}