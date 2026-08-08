class Solution {
public:

    int minPathSum_rec(vector<vector<int>> grid, int m, int n, vector<vector<int>>&dp){
        if(m==1 && n==1){
            return grid[m-1][n-1];
        }

        if(dp[m][n]!=-1) return dp[m][n];

        int upper_part=INT_MAX-1;
        int left_part=INT_MAX-1;

        if(m!=1){
            upper_part=minPathSum_rec(grid, m-1, n, dp);
        }

        if(n!=1){
            left_part=minPathSum_rec(grid,m,n-1,dp);
        }

        int sum=grid[m-1][n-1]+min(upper_part, left_part);

        return dp[m][n]=sum;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));

        return minPathSum_rec(grid, m, n, dp);
    }
};