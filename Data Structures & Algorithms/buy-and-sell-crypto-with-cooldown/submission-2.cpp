class Solution {
private:
    vector<vector<int>> memo;

    int dfs(int i, bool buying, const vector<int>& prices) {
        if (i >= prices.size()) return 0;
        if (memo[i][buying] != -1) return memo[i][buying];

        int cooldown = dfs(i + 1, buying, prices);
        if (buying) {
            int buy = dfs(i + 1, false, prices) - prices[i];
            memo[i][buying] = max(buy, cooldown);
        } else {
            // If we sell, we jump to i + 2 because of the mandatory cooldown day
            int sell = dfs(i + 2, true, prices) + prices[i];
            memo[i][buying] = max(sell, cooldown);
        }

        return memo[i][buying];
    }

public:
    int maxProfit(vector<int>& prices) {
        // memo[i][0] = max profit starting at day i, looking to sell
        // memo[i][1] = max profit starting at day i, looking to buy
        memo.assign(prices.size(), vector<int>(2, -1));
        return dfs(0, true, prices);
    }
};