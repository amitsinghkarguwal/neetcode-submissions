#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> s1; // Input stack
    stack<int> s2; // Output stack

public:
    MyQueue() {
    }
    
    // Time Complexity: O(1)
    void push(int x) {
        s1.push(x);
    }
    
    // Time Complexity: Amortized O(1), Worst case O(N)
    int pop() {
        // Call peek to ensure s2 has the oldest element ready
        peek();
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    // Time Complexity: Amortized O(1), Worst case O(N)
    int peek() {
        // If s2 is empty, we must transfer everything from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        // The oldest element is now at the top of s2
        return s2.top();
    }
    
    // Time Complexity: O(1)
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */