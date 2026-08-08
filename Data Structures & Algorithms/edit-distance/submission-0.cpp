//Recursive +memoization DP Code

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function for Top-Down Recursion
    // Passing strings as 'const string&' so we don't accidentally copy them!
    int editDistance_rec(const string& word1, const string& word2, int i, int j, vector<vector<int>>& dp) {
        
        // 1. BASE CASES: One of the strings is empty
        if (i == 0) return j; // word1 is empty, we must INSERT 'j' characters.
        if (j == 0) return i; // word2 is empty, we must DELETE 'i' characters.
        
        // 2. MEMORY CHECK
        if (dp[i][j] != -1) return dp[i][j];
        
        // 3. MATCH SCENARIO
        if (word1[i - 1] == word2[j - 1]) {
            // No cost added, just move both pointers backward
            return dp[i][j] = editDistance_rec(word1, word2, i - 1, j - 1, dp);
        }
        
        // 4. MISMATCH SCENARIO
        // Try all three edits and find the minimum cost path
        int insert_op  = editDistance_rec(word1, word2, i, j - 1, dp);
        int delete_op  = editDistance_rec(word1, word2, i - 1, j, dp);
        int replace_op = editDistance_rec(word1, word2, i - 1, j - 1, dp);
        
        // Add 1 for the current operation, plus the minimum of the three choices
        return dp[i][j] = 1 + min({insert_op, delete_op, replace_op});
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // Create DP table initialized to -1 (meaning uncalculated)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        // Start the recursion with pointers at the very end of both strings
        return editDistance_rec(word1, word2, m, n, dp);
    }
};