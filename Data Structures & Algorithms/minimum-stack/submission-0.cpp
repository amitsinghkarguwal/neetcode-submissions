#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
private:
    stack<pair<int, int>> st;

public:
    MinStack() {
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            // Calculate the new minimum by comparing the new value
            // with the minimum stored in the element just below it.
            int current_min = min(val, st.top().second);
            st.push({val, current_min});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};