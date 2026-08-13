#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        // Instant edge-case check: If the destination is a '1', it's impossible.
        if (s[n - 1] == '1') {
            return false;
        }
        
        // dp[i] will be true if we can reach index i
        vector<bool> dp(n, false);
        dp[0] = true; 
        
        // Tracks how many valid launch pads exist in the window [i - maxJump, i - minJump]
        int active_jumps = 0;
        
        for (int i = 1; i < n; i++) {
            
            // 1. Add the point that just entered the back of our allowed range
            if (i >= minJump && dp[i - minJump]) {
                active_jumps++;
            }
            
            // 2. Remove the point that just fell out of our allowed range
            if (i > maxJump && dp[i - maxJump - 1]) {
                active_jumps--;
            }
            
            // 3. If there is at least one valid launch pad, and we can land here
            if (active_jumps > 0 && s[i] == '0') {
                dp[i] = true;
            }
        }
        
        return dp[n - 1];
    }
};