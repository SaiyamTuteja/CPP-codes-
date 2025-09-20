#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Tree
{
public:
    void inorder(Node *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void preorder(Node *root)
    {
        if (root == nullptr)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node *root)
    {
        if (root == nullptr)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    int CountNodes(Node *root)
    {

        if (root == NULL)
            return 0;
        int leftCount = CountNodes(root->left);
        int rightCount = CountNodes(root->right);
        return leftCount + rightCount + 1;
    }
    Node *insertNode(Node *root, int data)
    {
        if (root == nullptr)
        {
            return new Node(data);
        }
        if (data > root->data)
        {
            root->right = insertNode(root->right, data);
        }
        else
        {
            root->left = insertNode(root->left, data);
        }
        return root;
    }
};

int main()
{
    Tree obj;
    Node *root = nullptr;
    int values[] = {10, 20, 30, 40, 50, 60, 90, 30, 50, 60};
    for (int val : values)
    {
        root = obj.insertNode(root, val);
    }
    cout << "Total nodes: " << obj.CountNodes(root) << endl;
}