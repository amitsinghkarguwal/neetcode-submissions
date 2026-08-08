///can't be greedy here, take example of 12(9,1,1,1), 12(4+4+4, 3).

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Helper function returning the MINIMUM squares needed to sum to n
    int solve(int n, vector<int>& memo) {
        
        // 1. BASE CASE: A sum of 0 requires 0 squares
        if (n == 0) return 0;
        
        // 2. MEMORY CHECK
        if (memo[n] != -1) return memo[n];
        
        // We want the minimum, so initialize with the maximum possible value
        int min_squares = INT_MAX;
        
        // 3. EXPLORE: Try every perfect square less than or equal to n
        for (int i = 1; i * i <= n; i++) {
            
            int square = i * i;
            
            // We use 1 square (i*i), and recursively solve for the remainder
            int current_squares = 1 + solve(n - square, memo);
            
            // Keep track of the absolute best path
            min_squares = min(min_squares, current_squares);
        }
        
        // 4. CACHE & RETURN
        return memo[n] = min_squares;
    }

    int numSquares(int n) {
        // DP table initialized to -1. Size is n + 1.
        vector<int> memo(n + 1, -1);
        
        return solve(n, memo);
    }
};