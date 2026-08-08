//dealing with the obstacles, here the tabulation method will help more.

class Solution {
public:


    int uniquePaths_rec(int m, int n, vector<vector<int>>& dp){

        if(m==1 || n==1) return dp[m][n]; 
        if(dp[m][n]==-2) return 0; //-2 denotes a wall

        if(dp[m][n]!=-1) return dp[m][n];

        return dp[m][n]=uniquePaths_rec(m-1, n, dp) + uniquePaths_rec(m,n-1, dp);
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if(obstacleGrid[0][0] == 1) return 0;


        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    //it is a obstacle;
                    dp[i+1][j+1]=-2;
                }
            }
        }


        int flag_hori=0;
        int flag_verti=0;

        for(int i=1;i<m+1;i++){
            if(dp[i][1]==-2) flag_verti=1;

            if(flag_verti) dp[i][1]=0;
            else dp[i][1]=1;
        }

        for(int j=1;j<n+1;j++){
            if(dp[1][j]==-2) flag_hori=1;
            
            if(flag_hori) dp[1][j]=0;
            else dp[1][j]=1;
        }

        int ans=uniquePaths_rec(m,n,dp);

        return ans;

        


        
    }
};
