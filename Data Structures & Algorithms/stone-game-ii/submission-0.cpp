#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(vector<int>& piles, vector<int>& suffix_sum, int i, int M, vector<vector<int>>& dp) {
        int n = piles.size();
        
        // BASE CASE 1: No piles left
        if (i == n) return 0;
        
        // BASE CASE 2: You can take all the remaining piles!
        if (i + 2 * M >= n) {
            return suffix_sum[i]; 
        }
        
        // MEMORY CHECK
        if (dp[i][M] != -1) return dp[i][M];
        
        int max_stones = 0;
        
        // ITERATE through all valid choices of X (1 to 2M)
        for (int X = 1; X <= 2 * M; X++) {
            
            // The opponent will play from index i + X, with the new M
            int opponent_score = solve(piles, suffix_sum, i + X, max(M, X), dp);
            
            // Your score is the total stones left minus what the opponent manages to secure
            int my_score = suffix_sum[i] - opponent_score;
            
            // Keep track of the best possible choice
            max_stones = max(max_stones, my_score);
        }
        
        return dp[i][M] = max_stones;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        vector<int> suffix_sum(n);
        suffix_sum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_sum[i] = piles[i] + suffix_sum[i + 1];
        }
        
        // DP table: dp[index][M]. 
        // Max M can theoretically be N.
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        // Start game at index 0, with M = 1
        return solve(piles, suffix_sum, 0, 1, dp);
    }
};