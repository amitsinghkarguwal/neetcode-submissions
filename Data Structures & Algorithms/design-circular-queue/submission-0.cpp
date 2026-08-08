#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> q;
    int head;
    int count;
    int capacity;

public:
    // Initialize the queue with a fixed size of k
    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
        head = 0;
        count = 0;
    }
    
    // Time Complexity: O(1)
    bool enQueue(int value) {
        if (isFull()) return false;
        
        // Calculate the next available empty index
        int next_tail = (head + count) % capacity;
        q[next_tail] = value;
        count++;
        
        return true;
    }
    
    // Time Complexity: O(1)
    bool deQueue() {
        if (isEmpty()) return false;
        
        // Shift head forward, wrapping around if it hits the end
        head = (head + 1) % capacity;
        count--;
        
        return true;
    }
    
    // Time Complexity: O(1)
    int Front() {
        if (isEmpty()) return -1;
        
        return q[head];
    }
    
    // Time Complexity: O(1)
    int Rear() {
        if (isEmpty()) return -1;
        
        // Calculate the index of the most recently added element
        int current_tail = (head + count - 1) % capacity;
        return q[current_tail];
    }
    
    // Time Complexity: O(1)
    bool isEmpty() {
        return count == 0;
    }
    
    // Time Complexity: O(1)
    bool isFull() {
        return count == capacity;
    }
};
