#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *CreateNode(int data) {
    return new Node{data, nullptr, nullptr};
}

Node *insertNode(Node *root, int data) {
    if (root == nullptr)
        return new Node{data, nullptr, nullptr};

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    return root;
}

void inOrder(Node *rt) {
    if (rt == nullptr)
        return;
    inOrder(rt->left);
    printf("%d \t", rt->data);
    inOrder(rt->right);
}

int countNodes(Node *root) {
    if (root == nullptr)
        return 0;
    int leftNodeCount = countNodes(root->left);
    int rightNodeCount = countNodes(root->right);
    return leftNodeCount + rightNodeCount + 1;
}

int main() {
    Node *root = nullptr;
    int values[] = {10, 50, 30, 40, 80, 60, 70, 20, 90, 100};

    for (int val : values)
        root = insertNode(root, val);

    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << "\n";

    int totalNodes = countNodes(root);
    cout << "Total number of nodes: " << totalNodes << endl;

    return 0;
}
