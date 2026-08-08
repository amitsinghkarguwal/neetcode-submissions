class Solution {
public:

    int knapsack_rec( vector<int> &nums, int n,int sum, vector<vector<int>> &dp){
        
        if(n==0){
            if(sum==0) return 1;
            return 0;
        }
        
        if(dp[sum][n]!=-1) return dp[sum][n];
        

        if(nums[n-1]<=sum){
            int take=knapsack_rec(nums, n-1, sum-nums[n-1], dp);
            int not_take=knapsack_rec(nums, n-1, sum, dp);

            return dp[sum][n]=take+not_take;
        }
        
        else{
            int not_take=knapsack_rec(nums, n-1, sum, dp);
            return dp[sum][n]=not_take;
        }
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        int total_sum=0;
        for(auto i: nums){
            total_sum+=i;
        }

        if((target + total_sum) % 2 != 0) return 0;

        int sum = (target + total_sum) / 2;

        vector<vector<int>> dp( sum+1, vector<int>(n+1,-1)); 

        return knapsack_rec(nums, n, sum, dp);
        
    }
};

