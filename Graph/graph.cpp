#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};
void preOrder(struct Node *rt, int value)
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
void inOrder(struct Node *rt, int value)
{
    postOrder(rt->left);
    printf("%d \n", rt->data);
    postOrder(rt->right);
}
int main()
{
    return 0;
}