class Solution {
public:

    int solve_rec(int n, vector<int>& dp){
        if(n==0) return 0;
        if(n==2 || n==1) return 1;

        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve_rec(n-1, dp)+solve_rec(n-2, dp)+solve_rec(n-3,dp);

    }
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return solve_rec(n, dp);
    }
};