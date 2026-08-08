#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        
        // Convert the dictionary vector to a hash set for O(1) lookups
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        
        // dp[i] represents the minimum extra characters in the substring s[0...i-1]
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            // Default move: Treat the newest character as an extra "garbage" character
            dp[i] = dp[i - 1] + 1;
            
            // Look backward to see if a valid dictionary word ends at position i
            for (int j = 0; j < i; j++) {
                string suffix = s.substr(j, i - j);
                
                // If we found a valid word, see if this path yields fewer extra characters
                if (dict.find(suffix) != dict.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        
        // The final answer for the entire string is stored at the very end of the array
        return dp[n];
    }
};