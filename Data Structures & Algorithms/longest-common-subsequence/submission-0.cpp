class Solution {
public:

    int lcs_rec(string text1, string text2, int m, int n, vector<vector<int>>& dp){
        if(m==0 || n==0){
            return 0;
        }

        if(dp[m][n]!=-1){
            return dp[m][n];
        }

        if(text1[m-1]==text2[n-1]){
            return dp[m][n]=1+lcs_rec(text1, text2, m-1, n-1, dp);
        }
        else{
            int omit_from_first=lcs_rec(text1, text2, m, n-1, dp);
            int omit_from_second=lcs_rec(text1, text2, m-1, n, dp);

            return dp[m][n]=max(omit_from_first, omit_from_second);
        }
    }


    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        return lcs_rec(text1, text2, m, n, dp);
    }
};
