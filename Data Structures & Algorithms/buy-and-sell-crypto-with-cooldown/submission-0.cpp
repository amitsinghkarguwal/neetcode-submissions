#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initial states before day 0
        int hold = INT_MIN; // Max profit if we hold a stock
        int sold = 0;       // Max profit if we just sold a stock
        int rest = 0;       // Max profit if we are resting/cooldown
        
        for (int price : prices) {
            int prev_sold = sold; // Keep track of yesterday's sold state
            
            // To be in 'sold' state today, we must have 'held' a stock yesterday and sold it at today's price.
            sold = hold + price;
            
            // To be in 'hold' state, we either keep holding the stock from yesterday, 
            // or we buy today (meaning we transition from the 'rest' state yesterday).
            hold = max(hold, rest - price);
            
            // To be in 'rest' state, we either continue resting, 
            // or we transition into rest because we 'sold' yesterday.
            rest = max(rest, prev_sold);
        }
        
        // The maximum profit will either be in the 'sold' state or 'rest' state.
        // It's never optimal to end the last day still holding a stock.
        return max(sold, rest);
    }
};