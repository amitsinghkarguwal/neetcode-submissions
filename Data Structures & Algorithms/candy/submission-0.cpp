#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        
        // Rule 1: Every child gets at least 1 candy
        vector<int> candies(n, 1);
        
        // Pass 1: Left to Right
        // Ensure a child has more candies than their left neighbor if their rating is higher
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        // Pass 2: Right to Left
        // Ensure a child has more candies than their right neighbor if their rating is higher
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                // Use max to preserve the condition satisfied in the first pass
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        // Sum the total candies required
        int totalCandies = 0;
        for (int c : candies) {
            totalCandies += c;
        }
        
        return totalCandies;
    }
};