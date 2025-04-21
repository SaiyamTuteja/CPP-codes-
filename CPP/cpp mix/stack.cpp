#include <bits/stdc++.h>
using namespace std;
#define n 5
class Stack
{
private:
    int *arr;
    int top;

public:
    Stack()
    {

        arr = new int[n];
        top = -1;
    }
    ~Stack()
    {
        delete[] arr;
    }
    int push(int item)
    {
        if (top >= n - 1)
        {
            cout << "Overflow Exits" << endl;
            return 0;
        }
        else
        {
            arr[++top] = item;
        }
    }
    void pop()
    {
        if (top < 0)
        {
            cout << "underflow Exits";
            return;
        }
        else
        {
            int item = arr[top--];
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Overflow exits" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < top; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Stack S;
    int item;
    int choice;

    while (true)
    {
        cout << "Enter the operation to perform:\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter the choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the item to insert: ";
            cin >> item;
            S.push(item);
            break;
        case 2:
            S.pop();
            break;
        case 3:
            S.display();
            break;
        case 4:
            return 0; // Exiting the program
        default:
            cout << "Enter a valid choice:" << endl;
        }
    }
}