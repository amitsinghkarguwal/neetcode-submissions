//using DP

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            // result[i] = result[number without lowest set bit] + 1
            result[i] = result[i & (i - 1)] + 1; 
        }
        
        return result;
    }
};