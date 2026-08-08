class Solution {
public:

    int uniquePaths_rec(int m, int n, vector<vector<int>>& dp){
        if(m==1 || n==1) return 1; //it can also handles the grid 1X1 also, where robot is at finish line already, hence 1 way.

        if(dp[m][n]!=-1) return dp[m][n];

        return dp[m][n]=uniquePaths_rec(m-1, n, dp) + uniquePaths_rec(m,n-1, dp);

    }


    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        int ans= uniquePaths_rec(m, n, dp);
        return ans;
    }
};
