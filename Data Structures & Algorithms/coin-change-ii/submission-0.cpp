class Solution {
public:

    int knapsack_rec_unbounded(vector<int> &coins, int amount, int n, vector<vector<int>> &dp){

        if(n==0){
            if(amount==0) return 1;
            return 0;
        }
        
        if(dp[amount][n]!=-1){
            return dp[amount][n];
        }
        
        if(coins[n-1]<=amount){
            int take=knapsack_rec_unbounded(coins, amount-coins[n-1], n,dp); //see here n remains n only
            int not_take=knapsack_rec_unbounded(coins, amount, n-1,dp);
            return dp[amount][n]=take + not_take;
        }
        
        else{
            int not_take=knapsack_rec_unbounded(coins, amount, n-1,dp);
            return dp[amount][n]=not_take;
        }
    }



    int change(int amount, vector<int>& coins) {

        int n=coins.size();
        vector<vector<int>> dp( amount+1, vector<int>(n+1,-1));
        
        return knapsack_rec_unbounded(coins, amount, n, dp);
        
    }
};
