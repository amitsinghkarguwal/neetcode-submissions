// memoization code fronting

class Solution {
public:
    int solve_rec(string& s, int index, vector<int>& memo) {

        if (index == s.length()) {
            return 1;
        }

        if (s[index] == '0') {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        int ways = solve_rec(s, index + 1, memo);

        // Choice 2: Take two characters (if we have at least 2 left and they form 10 to 26)
        if (index + 1 < s.length()) {

            int twoDigits = (s[index] - '0') * 10 + (s[index + 1] - '0');

            if (twoDigits >= 10 && twoDigits <= 26) {
                ways += solve_rec(s, index + 2, memo);
            }
        }

        return memo[index] = ways;
    }

    int numDecodings(string s) {
        // Initialize a 1D memoization array with -1
        vector<int> memo(s.length(), -1);
        
        // Start decoding from index 0
        return solve_rec(s, 0, memo);
    }
};