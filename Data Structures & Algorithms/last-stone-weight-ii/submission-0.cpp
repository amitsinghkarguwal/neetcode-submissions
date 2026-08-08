#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int knapsack_rec(vector<int> &stones, int n, int sum, vector<vector<int>> &dp){
        
        if(n == 0 || sum == 0){
            return 0; 
        }
        
        if(dp[sum][n] != -1) return dp[sum][n];
        
        if(stones[n-1] <= sum){
            // 2. We add the stone's weight when we 'take' it
            int take = stones[n-1] + knapsack_rec(stones, n-1, sum - stones[n-1], dp);
            int not_take = knapsack_rec(stones, n-1, sum, dp);

            return dp[sum][n] = max(take, not_take);
        }
        else{
            int not_take = knapsack_rec(stones, n-1, sum, dp);
            return dp[sum][n] = not_take;
        }
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int total_sum = 0;
        for(auto i : stones){
            total_sum += i;
        }

        // Our target capacity is exactly half the total weight
        int sum = total_sum / 2;

        vector<vector<int>> dp(sum + 1, vector<int>(n + 1, -1)); 

        // This gives us the heaviest possible Pile 1
        int max_pile_1 = knapsack_rec(stones, n, sum, dp);
        
        // The final smashed stone is just the Total Weight minus both piles!
        return total_sum - (2 * max_pile_1);
    }
};