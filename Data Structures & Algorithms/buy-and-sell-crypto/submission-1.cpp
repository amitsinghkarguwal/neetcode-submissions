class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i=0;
        int j=i+1;
        int max_profit=0;
        while(j < prices.size()){
            if(prices[j]<prices[i]){
                i=j;
                j=i+1;
                continue;
            }
            max_profit=max(max_profit, prices[j]-prices[i]);
            j++;
        }

        return max_profit;
    }


};
