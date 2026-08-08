#include <unordered_map>
#include <stack>

using namespace std;

class FreqStack {
private:
    unordered_map<int, int> freq;
    
    unordered_map<int, stack<int>> group_stacks;
    
    int max_freq;

public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        
        if (freq[val] > max_freq) {
            max_freq = freq[val];
        }
        
        group_stacks[freq[val]].push(val);
    }
    
    // Time Complexity: O(1)
    int pop() {
        int val = group_stacks[max_freq].top();
    
        group_stacks[max_freq].pop();
        
        freq[val]--;

        if (group_stacks[max_freq].empty()) {
            max_freq--;
        }
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */