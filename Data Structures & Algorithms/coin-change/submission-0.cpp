class Solution {
public:

    int knapsack_rec_unbounded(vector<int> &coins, int amount, int n, vector<vector<int>> &dp){

        // 1. Success Base Case: It takes exactly 0 coins to make an amount of 0
        if(amount == 0) return 0;
        
        // 2. Failure Base Case: Out of coins but amount > 0. Return a massive number.
        if(n == 0) return 1e9;
        
        if(dp[amount][n]!=-1){
            return dp[amount][n];
        }
        
        if(coins[n-1]<=amount){
            int take=1 + knapsack_rec_unbounded(coins, amount-coins[n-1], n,dp); //see here n remains n only
            int not_take=knapsack_rec_unbounded(coins, amount, n-1,dp);
            return dp[amount][n]=min(take, not_take);
        }
        
        else{
            int not_take=knapsack_rec_unbounded(coins, amount, n-1,dp);
            return dp[amount][n]=not_take;
        }
    }



    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp( amount+1, vector<int>(n+1,-1));
        
        int ans=knapsack_rec_unbounded(coins, amount, n, dp);
        
        // 4. If the answer is greater than or equal to our "Infinity", it's impossible
        if(ans >= 1e9) return -1;

        return ans;
    }
};
