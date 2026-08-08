#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // dp[i] represents the maximum score differential the current player 
        // can achieve starting from index i.
        // Size is n + 1 to easily handle the base case where no stones are left.
        vector<int> dp(n + 1, 0);
        
        // Process the game backwards
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MIN; // Start with the lowest possible value
            int take = 0;    // Running total of stones taken this turn
            
            // We can take 1, 2, or 3 stones (as long as we don't go out of bounds)
            for (int k = 0; k < 3 && i + k < n; k++) {
                take += stoneValue[i + k];
                
                // The brilliant transition:
                // My Advantage = (Stones I just took) - (Opponent's Advantage from remaining stones)
                dp[i] = max(dp[i], take - dp[i + k + 1]);
            }
        }
        
        // dp[0] now holds Alice's max differential for the whole game
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};