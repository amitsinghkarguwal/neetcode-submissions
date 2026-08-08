class Solution {
public:

    int knapsack_rec( vector<int> &nums, int n,int sum, vector<vector<int>> &dp){
        
        // 1. EARLY EXIT: We hit the target sum exactly! No need to check remaining items.
        if(sum == 0) return 1;
        
        // 2. We ran out of items and the sum is still not 0.
        if(n == 0) return 0;
        
        if(dp[sum][n]!=-1) return dp[sum][n];
        

        if(nums[n-1]<=sum){
            bool take=knapsack_rec(nums, n-1, sum-nums[n-1], dp);
            bool not_take=knapsack_rec(nums, n-1, sum, dp);

            return dp[sum][n]=take || not_take;
        }
        
        else{
            bool not_take=knapsack_rec(nums, n-1, sum, dp);
            return dp[sum][n]=not_take;
        }
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int total_sum=0;
        for(auto i: nums){
            total_sum+=i;
        }

        if((total_sum) % 2 != 0) return 0;

        int sum = (total_sum) / 2;

        vector<vector<int>> dp( sum+1, vector<int>(n+1,-1)); 

        return knapsack_rec(nums, n, sum, dp);
    }


};

