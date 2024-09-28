
class MyCircularDeque {
private:
    vector<int> deque;               // Array to store deque elements
    int front, rear, size, capacity; // Pointers and capacity

public:
    // Constructor, initialize the deque with given capacity
    MyCircularDeque(int k) {
        deque.resize(k);
        capacity = k;
        front = 0;
        rear = 0;
        size = 0;
    }

    // Insert an element at the front of the deque
    bool insertFront(int value) {
        if (isFull()) {
            return false; // Deque is full, can't insert
        }
        front =
            (front - 1 + capacity) % capacity; // Move front pointer backward
        deque[front] = value;                  // Insert element at the front
        size++;
        return true;
    }

    // Insert an element at the rear of the deque
    bool insertLast(int value) {
        if (isFull()) {
            return false; // Deque is full, can't insert
        }
        deque[rear] = value;          // Insert element at the rear
        rear = (rear + 1) % capacity; // Move rear pointer forward
        size++;
        return true;
    }

    // Delete an element from the front of the deque
    bool deleteFront() {
        if (isEmpty()) {
            return false; // Deque is empty, can't delete
        }
        front = (front + 1) % capacity; // Move front pointer forward
        size--;
        return true;
    }

    // Delete an element from the rear of the deque
    bool deleteLast() {
        if (isEmpty()) {
            return false; // Deque is empty, can't delete
        }
        rear = (rear - 1 + capacity) % capacity; // Move rear pointer backward
        size--;
        return true;
    }

    // Get the front element of the deque
    int getFront() {
        if (isEmpty()) {
            return -1; // Deque is empty
        }
        return deque[front];
    }

    // Get the last element of the deque
    int getRear() {
        if (isEmpty()) {
            return -1; // Deque is empty
        }
        return deque[(rear - 1 + capacity) % capacity];
    }

    // Check if the deque is empty
    bool isEmpty() { return size == 0; }

    // Check if the deque is full
    bool isFull() { return size == capacity; }
};