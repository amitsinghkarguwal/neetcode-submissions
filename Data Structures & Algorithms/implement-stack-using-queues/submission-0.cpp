#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
        // Constructor: Nothing needed here since the queue is automatically initialized.
    }
    
    // Time Complexity: O(N)
    void push(int x) {
        // 1. Add the new element to the back
        q.push(x);
        
        // 2. Rotate the previous elements behind the new element
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    // Time Complexity: O(1)
    int pop() {
        // The newest element is always at the front, ready to be popped
        int val = q.front();
        q.pop();
        return val;
    }
    
    // Time Complexity: O(1)
    int top() {
        return q.front();
    }
    
    // Time Complexity: O(1)
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */