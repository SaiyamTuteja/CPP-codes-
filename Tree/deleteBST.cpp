#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
class BST
{
public:
    Node *insertNode(Node *root, int data)
    {

        if (root == nullptr)
            return new Node(data);

        if (data < root->data)
        {
            root->left = insertNode(root->left, data);
        }
        else
        {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
    Node *minVal(Node *root)
    {
        if (root == NULL)
            return NULL;
        Node *temp = root;
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }

    void inOrder(Node *root)
    {
        if (root == NULL)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
        return;
    }
    void preOrder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
        return;
    }

    void maxVal(Node *root)
    {
        if (root == NULL)
        {
            cout << "tree is empty:";
            return;
        }
        if (root->right != NULL)
        {
            maxVal(root->right);
            return;
        }
        cout << root->data << " ";
        return;
    }
    Node *DeleteNodeBst(Node *root, int value)
    {
        if (root == nullptr)
            return root;

        if (value < root->data)
        {
            root->left = DeleteNodeBst(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = DeleteNodeBst(root->right, value);
        }
        else
        {
            // Leaf
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            // One child
            if (root->left != nullptr && root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            if (root->right != nullptr && root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            // Two children
            Node *mini = minVal(root->right);
            root->data = mini->data;
            root->right = DeleteNodeBst(root->right, mini->data);
        }
        return root;
    }
};
int main()
{
    BST tree;
    Node *root = nullptr;
    int values[] = {20, 10, 22, 44, 21, 59};

    for (int val : values)
        root = tree.insertNode(root, val);

    cout << "Inorder :\n";
    tree.inOrder(root);

    cout << "\nPreorder:\n";
    tree.preOrder(root);

    Node *mini = tree.minVal(root);
    if (mini != nullptr)
        cout << "\nMinimum Element: " << mini->data << endl;

    cout << "Max element of tree: ";
    tree.maxVal(root);
    cout << endl;

    cout << "Deleting 22...\n";
    root = tree.DeleteNodeBst(root, 22);

    cout << "Tree after deletion (inorder):\n";
    cout << "Deleting 10...\n";
    root = tree.DeleteNodeBst(root, 10);
    cout << "Tree after deletion (inorder):\n";
    tree.inOrder(root);
    cout << endl;

    return 0;
}
