#include <stack>

using namespace std;

class StockSpanner {
private:
    // Stack stores pairs of {price, span}
    stack<pair<int, int>> st;

public:
    StockSpanner() {
        // Constructor is empty as the stack initializes itself
    }
    
    int next(int price) {
        int span = 1;
        
        while (!st.empty() && st.top().first <= price) {
            
            span += st.top().second;
            
            st.pop();
        }
        
        // Push the current price and its total accumulated span
        st.push({price, span});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */