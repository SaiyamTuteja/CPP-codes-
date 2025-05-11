#include <bits/stdc++.h>
using namespace std;

#define SIZE 20
int arr[SIZE];
int top = -1;

void push(int data)
{
    if (top == SIZE - 1)
    {
        cout << "Stack overflow\n";
    }
    else
    {
        arr[++top] = data;
        cout << "Element inserted successfully: " << data << endl;
    }
}

bool empty()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return true;
    }
    return false;
}

void pop()
{
    if (empty())
    {
        return;
    }
    int temp = arr[top--];
    cout << "Element deleted successfully: " << temp << endl;
}

bool isFull()
{
    if (top == SIZE - 1)
    {
        cout << "Stack is full\n";
        return true;
    }
    return false;
}

void print()
{
    if (empty())
        return;
    cout << "Stack elements: ";
    for (int i = 0; i <= top; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    while (true)
    {
        int choice;
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Check Empty\n5. Check Full\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter the element to push to the stack: ";
            cin >> data;
            push(data);
            break;
        }
        case 2:
            pop();
            break;
        case 3:
            print();
            break;
        case 4:
            empty();
            break;
        case 5:
            isFull();
            break;
        case 6:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Enter a valid choice.\n";
        }
    }
}
