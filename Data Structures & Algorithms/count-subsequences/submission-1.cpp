#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // Use unsigned long long to prevent integer overflow on large intermediate results
        // dp[i][j] is the number of ways to form t[0...j-1] using s[0...i-1]
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        
        // Base case: An empty string `t` can be formed exactly 1 way from any prefix of `s` 
        // (by deleting all characters of `s`)
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }
        
        // Fill the table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // If the characters match, we sum the combinations of using it and skipping it
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } 
                // If they don't match, we can only skip the current character in `s`
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[m][n];
    }
};