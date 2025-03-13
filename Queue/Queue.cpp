#include <iostream>
using namespace std;

#define MAX 100 // Maximum queue size

class Queue
{
private:
    int arr[MAX]; // Array to store queue elements
    int front, rear;

public:
    Queue()
    {
        front = -1; // Initialize front and rear
        rear = -1;
    }

    void push(int x)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1)
            front = 0; // Set front for first element

        arr[++rear] = x; // Insert element at rear
    }

    void pop()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        front++; // Move front pointer forward
    }

    int peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front]; // Return front element
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }
};

int main()
{
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.peek() << endl; // Output: 1
    q.pop();

    cout << q.peek() << endl; // Output: 2
    q.pop();

    cout << q.peek() << endl; // Output: 3
    q.pop();

    cout << q.isEmpty() << endl; // Output: 1 (true)

    return 0;
}
