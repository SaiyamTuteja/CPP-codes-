#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
private:
    int front, rear, size, capacity;
    int *arr;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    void push(int x) {
        if (size == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) front = 0;  // Set front for first element

        rear = (rear + 1) % capacity;  // Circular increment
        arr[rear] = x;
        size++;
    }

    void pop() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1) % capacity;  // Circular increment
        size--;
    }

    int peek() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return size == 0;
    }
    
    ~CircularQueue() {
        delete[] arr;  // Free memory
    }
};

int main() {
    CircularQueue q(5);  // Queue of size 5
    
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

