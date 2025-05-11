#include <iostream>
using namespace std;

#define SIZE 12
int Queue[SIZE];
int front = -1, rear = -1;

void enqueue(int data)
{
    if (rear == SIZE - 1)
    {
        cout << "Queue Overflow\n";
        return;
    }

    if (front == -1)
        front = 0; // first insertion
    Queue[++rear] = data;
    cout << "Element inserted successfully: " << data << endl;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow\n";
        return;
    }

    int temp = Queue[front++];
    cout << "Element deleted successfully: " << temp << endl;

    // Reset queue if empty
    if (front > rear)
    {
        front = rear = -1;
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
    {
        cout << Queue[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice, data;

    while (true)
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to enqueue: ";
            cin >> data;
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
