#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Helper function: Returns 1 if s[i...j] is a palindrome, 0 otherwise
    int check(const string& s, int i, int j, vector<vector<int>>& dp) {
        
        if(i==j) return 1; //happen in case of odd length substring
        if (i >= j) return 1; //happen in caes of even length substring like bb
        
        if (dp[i][j] != -1) return dp[i][j];
        

        if (s[i] == s[j]) {
            return dp[i][j] = check(s, i + 1, j - 1, dp);
        }

        return dp[i][j] = 0;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int start = 0;
        int max_len = 1;
        
        // Test every possible substring starting at i and ending at j
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                
                // If this specific substring is a valid palindrome
                if (check(s, i, j, dp) == 1) {
                    
                    int current_len = j - i + 1;
                    
                    // Is it the longest one we've found so far?
                    if (current_len > max_len) {
                        max_len = current_len;
                        start = i;
                    }
                }
            }
        }
        
        // Extract and return the physical substring
        return s.substr(start, max_len);
    }
};