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
}
void postOrder(struct Node *rt)
{

    postOrder(rt->left);
    postOrder(rt->right);
    printf("%d \n", rt->data);
}
void inOrder(struct Node *rt, int value)
{
    rt->data = value;
    rt->left;
}
int main()
{
    return 0;
}