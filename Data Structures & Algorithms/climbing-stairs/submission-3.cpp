//recursion + momoization approach

class Solution {
public:

    int climbStairs_rec(int n, vector<int>& dp){
        if(n==1) return 1;
        if(n==2) return 2;

        if(dp[n]!=-1) return dp[n];

        return dp[n]=climbStairs_rec(n-1, dp) + climbStairs_rec(n-2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

        int ans=climbStairs_rec(n, dp);
        return ans;
    }
};
