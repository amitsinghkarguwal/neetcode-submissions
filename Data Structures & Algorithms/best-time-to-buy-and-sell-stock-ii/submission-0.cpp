class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        // State 1: Maximum profit on day i if we are currently holding a stock
        int hold = -prices[0]; 
        
        // State 2: Maximum profit on day i if we are NOT holding a stock
        int notHold = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            // We either keep holding what we had, or we buy today's stock (spending money)
            hold = max(hold, notHold - prices[i]);
            
            notHold = max(notHold, hold + prices[i]);
        }
        
        return notHold;
    }
};