class Solution {
public:

    int stoneGame_rec(vector<int>& piles, int i, int j, vector<vector<int>>& dp){

        if(i==j){
            return piles[i];
        }

        if(i>j){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int taken_left_number=piles[i]-stoneGame_rec(piles, i+1, j, dp);
        int taken_right_number=piles[j]-stoneGame_rec(piles, i, j-1, dp);

        return dp[i][j]=max(taken_left_number, taken_right_number);
    }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int i=0;
        int j=n-1;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return (stoneGame_rec(piles, i, j, dp)>0); //function return the differcce alice is ahead of bob, if it is strictly greateer than bob.
    }
};