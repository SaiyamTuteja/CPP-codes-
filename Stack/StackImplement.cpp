#include <bits/stdc++.h>
using namespace std;
#define size 20
int top = -1;
int a[size];

int push(int value)
{
    if (top == size - 1)
    {
        cout << "Stack is full" << endl;
        return 0;
    }
    else
    {
        top++;
        a[top] = value;
        cout << "Element inserted sucessfull! \n";
    }
}
int pop()
{
    if (top == -1)
    {
        cout << "stack underdlow" << endl;
        return 0;
    }
    else
    {
        int val = a[top];
        top--;
        cout << "Element deleted: " << val << endl;
    }
}
int peek()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        cout << "Top element is: " << a[top] << endl;
    }
}
int full()
{
    if (top == size - 1)
    {
        cout << "Stack is full" << endl;
        return 0;
    }
    else
    {
        cout << "Stack is not full" << endl;
    }
}
int empty()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
}
void display()
{
    for (int i = 0; i <= top; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    do
    {

        int choice;
        cout << "1. Push\n2. Pop\n3. Peek\n4. Full\n5. Empty\n6. Display\n7. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter the value: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            full();
            break;
        case 5:
            empty();
            break;
        case 6:
            display();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (1);
    return 0;
}