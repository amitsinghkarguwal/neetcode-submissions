#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Helper function for Top-Down Recursion
    bool isMatch_rec(const string& s, const string& p, int i, int j, vector<vector<int>>& dp) {
        

        // 2. BASE CASE: The pattern is exhausted
        if (j == p.length()) {
            // If the pattern is done, the string MUST also be done to be a valid match.
            return dp[i][j] = (i == s.length());
        }

        if (dp[i][j] != -1) return dp[i][j];
        // 3. CURRENT MATCH: Do the characters at our current pointers match?
        // (Also handles the '.' wildcard and prevents out-of-bounds on the string)
        bool match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        // 4. THE STAR SCENARIO: Look ahead to see if the next pattern character is '*'
        if (j + 1 < p.length() && p[j + 1] == '*') {
            
            // CHOICE A: Skip the '*' and the character before it (Zero occurrences)
            bool skip = isMatch_rec(s, p, i, j + 2, dp);
            
            // CHOICE B: Use the '*' (One or more occurrences). 
            // Only valid if the current characters match! Notice 'j' stays the same!
            bool use = match && isMatch_rec(s, p, i + 1, j, dp);
            
            return dp[i][j] = (skip || use);
        } 
        
        // 5. NORMAL SCENARIO: No '*' coming up.
        else {
            if (match) {
                // Characters matched, move both pointers forward
                return dp[i][j] = isMatch_rec(s, p, i + 1, j + 1, dp);
            } else {
                // Characters didn't match. Dead end.
                return dp[i][j] = 0; // false
            }
        }
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        // Start pointers at the beginning of both strings
        return isMatch_rec(s, p, 0, 0, dp);
    }
};