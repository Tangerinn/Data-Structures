#include <iostream>

using namespace std;

class Queue 
{
private:
    int maxCapacity, front, rear, currentSize;
    int* myQueue;

public:
    // Constructor
    Queue(int size) 
    {
        maxCapacity = size;
        front = 0;
        rear = -1;
        myQueue = new int[maxCapacity];
        currentSize = 0;
    }

    bool isFull() 
    {
        return currentSize == maxCapacity;
    }

    bool isEmpty() 
    {
        return currentSize==0;
    }

    void enqueue(int value) 
    {
        if (isFull()) 
        {
            cout << "Queue is full, cannot enqueue." << endl;
        } 
        else 
        {
            rear = (rear + 1 ) % maxCapacity;
            myQueue[rear] = value;
            cout << "Enqueued value " << value << endl;
            currentSize++;
        }
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Cannot dequeue, queue is empty." << endl;
        } else 
        {
            cout << "Dequeued value " << myQueue[front] << endl;
            front = (front + 1) % maxCapacity;
            currentSize--;
        }
    }

    void peek() {
        if (isEmpty()) 
        {
            cout << "Cannot peek, queue is empty." << endl;
        } else 
        {
            cout << "Value at the front is " << myQueue[front] << endl;
        }
    }
};

int main() 
{
    Queue myQueue(5);

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();

    myQueue.enqueue(6);
    myQueue.enqueue(7);
    
    return 0;
}
