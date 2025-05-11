#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    Node* InsertNode(Node* root, int data) {
        if (root == nullptr)
            return new Node(data);
        if (data < root->data)
            root->left = InsertNode(root->left, data);
        else
            root->right = InsertNode(root->right, data);
        return root;
    }

    int sumNodes(Node* root) {
        if (root == nullptr)
            return 0;
        return root->data + sumNodes(root->left) + sumNodes(root->right);
    }
};

int main() {
    int arr[] = {10, 50, 30, 40, 80, 60, 70, 20, 90, 100};
    Node *tree = new Node(arr[0]);
    for (int i = 1; i < 10; ++i) {
        tree = tree->InsertNode(tree, arr[i]);
    }

    int FinalSum = tree->sumNodes(tree);
    cout << "Total Sum Of Nodes is: " << FinalSum << endl;

    return 0;
}
