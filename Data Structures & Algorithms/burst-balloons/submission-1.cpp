class Solution {
public:
    int ans=0;

    int mcm_rec(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];


        int max_coins = 0;
        for (int k = i; k <= j; k++) {
            
            int left_cost = mcm_rec(nums, i, k-1, dp);
            int right_cost = mcm_rec(nums, k + 1, j, dp);
            int multiply_cost = nums[i-1]*nums[k]*nums[j+1];
            
            max_coins=max(max_coins , left_cost + right_cost + multiply_cost);
        }

        return dp[i][j] =max_coins;
    }

    int maxCoins(vector<int>& nums) {

        //padding one either side.
        int original_size = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int N=nums.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));

        return mcm_rec(nums, 1, N-2, dp);
    }
};
