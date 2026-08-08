#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function returning the max product achievable by breaking 'n'
    int solve(int n, vector<int>& memo) {
        
        // 1. BASE CASE: 1 cannot be broken any further.
        if (n == 1) return 1;
        
        // 2. MEMORY CHECK
        if (memo[n] != -1) return memo[n];
        
        int max_product = 0;
        
        // 3. EXPLORE: Try making a first cut of size 'i'
        for (int i = 1; i < n; i++) {
            
            // The magic line! We cut off 'i'. 
            // For the remainder (n - i), we take the best out of keeping it whole, 
            // or recursively breaking it further.
            int remainder_best = max(n - i, solve(n - i, memo));
            
            int current_product = i * remainder_best;
            
            // Keep track of the absolute highest product we can generate
            max_product = max(max_product, current_product);
        }
        
        // 4. CACHE & RETURN
        return memo[n] = max_product;
    }

    int integerBreak(int n) {
        // DP table initialized to -1. Size is n + 1.
        vector<int> memo(n + 1, -1);
        
        return solve(n, memo);
    }
};