#include <iostream>
using namespace std;

class Deque
{
private:
    int maxCapacity, currentSize, front, rear;
    int* myDeque;

public:
    // Constructor
    Deque(int size)
    {
        maxCapacity = size;
        currentSize = 0;
        front = -1;
        rear = -1;
        myDeque = new int[maxCapacity];
    }

    // Destructor to free memory
    ~Deque()
    {
        delete[] myDeque;
    }

    // Check if deque is full
    bool isFull()
    {
        return currentSize == maxCapacity;
    }

    // Check if deque is empty
    bool isEmpty()
    {
        return currentSize == 0;
    }

    // Insert an element at the front
    void insert_front(int value)
    {
        if (isFull())
        {
            cout << "Deque is full, cannot insert." << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front = (front - 1 + maxCapacity) % maxCapacity;
        }
        myDeque[front] = value;
        currentSize++;
        cout << "Inserted " << value << " at the front." << endl;
    }

    // Insert an element at the rear
    void insert_rear(int value)
    {
        if (isFull())
        {
            cout << "Deque is full, cannot insert." << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % maxCapacity;
        }
        myDeque[rear] = value;
        currentSize++;
        cout << "Inserted " << value << " at the rear." << endl;
    }

    // Remove an element from the front
    void pop_front()
    {
        if (isEmpty())
        {
            cout << "Deque is empty, cannot pop." << endl;
            return;
        }
        cout << "Popped " << myDeque[front] << " from the front." << endl;
        // If it's the last element, reset the deque
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % maxCapacity;
        }
        currentSize--;
    }

    // Remove an element from the rear
    void pop_rear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty, cannot pop." << endl;
            return;
        }
        cout << "Popped " << myDeque[rear] << " from the rear." << endl;
        // If it's the last element, reset the deque
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear = (rear - 1 + maxCapacity) % maxCapacity;
        }
        currentSize--;
    }
    
    // Print the contents of the deque
    void printDeque()
    {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << myDeque[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % maxCapacity;
        }
        cout << endl;
    }
};

int main()
{
    Deque myDeque(5);

    myDeque.insert_rear(10);
    myDeque.insert_rear(20);
    myDeque.insert_front(5);
    myDeque.printDeque(); // Expected: 5 10 20

    myDeque.pop_rear();
    myDeque.printDeque(); // Expected: 5 10
    
    myDeque.pop_front();
    myDeque.printDeque(); // Expected: 10

    return 0;
}
