class Solution {
public:

    int solve_rec(vector<int>& cost,int n, vector<int>& dp){

        if(n==0 || n==1){
            return 0;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        int min_cost=0;

        // n pe hum kaise aaye honge, ya toh n-1 se, ya toh n-2 se.
        int one_step=cost[n-1]+solve_rec(cost,n-1, dp);
        int two_step=cost[n-2]+solve_rec(cost, n-2, dp);
        min_cost=min(one_step, two_step);

        return dp[n]=min_cost;


    }
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
        vector<int> dp(n+1, -1);

        return solve_rec(cost, n , dp);
    }
};
