//core code of LCS interative (tabulation method) aka bottom up appraoch

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {

        int m=text1.size();
        int n=text2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        //base condition of recursion becomes here the intialization
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
            if(i==0 || j==0) dp[i][j]=0;
            }
        }


        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){

                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][ j-1];
                }

                else{
                    int omit_from_first=dp[i-1][j];
                    int omit_from_second=dp[i][j-1];
                    dp[i][j]=max(omit_from_first, omit_from_second);
                }
                
            }
        }

        return dp[m][n];
    }
};
