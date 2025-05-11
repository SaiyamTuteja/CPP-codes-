#include <bits/stdc++.h>
using namespace std;
#define size 20
int arr[size];
int top = -1;
void push(int data)
{
    if (top == size - 1)
    {
        cout << "stack overflow";
    }
    else
    {
        arr[top++] = data;
        cout << "Element inserted succesfully " << data;
    }
}
bool empty()
{
    if (top == -1)
    {
        cout << " stack is empty";
        return true;
    }
    else
    {
        return false;
    }
}

void pop()
{
    if (!empty())
    {
        return;
    }
    int temp = arr[top];
    arr[top--];
    cout << "Element deleted succesfully " << temp << endl;
}
bool isFull()
{
    if (top == size - 1)
    {
        cout << "element is full ";
        return true;
    }
    return false;
}
void print()
{

    for (int i = 0; i <= arr[top] - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int choice;
    cout << "Enter the choice :";
    cout << "1. push \n 2. pop \n 3. dispalay \n 4.empty \n 5. full \n 6. exit  \n ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        int data;
        cout << "enter the element to push to the stack :";
        cin >> data;
        push(data);
        break;

    case 2:
        pop();
        break;
    case 4:
        print();
        break;
    case 5:
        empty();
        break;
    case 6:
        isFull();
        break;
    default:
        cout << "enter the valid choice " << endl;
        break;
    }
    return 0;
}