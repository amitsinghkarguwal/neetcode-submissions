#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    // Helper function for Top-Down Recursion
    // Returns 1 (true) if the substring starting at 'start_index' can be broken, 0 (false) otherwise
    int wordBreak_rec(const string& s, const unordered_set<string>& wordSet, int start_index, vector<int>& memo) {
        
        // 1. BASE CASE: If we've successfully partitioned the entire string and reached the end
        if (start_index == s.length()) {
            return 1; 
        }
        
        // 2. MEMORY CHECK: Have we solved the subproblem for this index before?
        if (memo[start_index] != -1) {
            return memo[start_index];
        }
        
        // 3. EXPLORE: Try placing a partition at every possible point after start_index
        string current_word = "";
        for (int end_index = start_index; end_index < s.length(); end_index++) {
            
            // Build the string character by character (faster than using s.substr repeatedly)
            current_word += s[end_index];
            
            // CHOOSE: If the left chunk is a valid dictionary word...
            if (wordSet.count(current_word)) {
                
                // ...ask recursion to solve the remaining right chunk!
                if (wordBreak_rec(s, wordSet, end_index + 1, memo) == 1) {
                    return memo[start_index] = 1; // Success! Cache and return.
                }
            }
        }
        
        // 4. UN-CHOOSE / FAILURE: If no partition worked from this start_index, it's a dead end.
        return memo[start_index] = 0; 
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // OPTIMIZATION: Convert the vector dictionary into a Hash Set. 
        // This makes checking "Is this a valid word?" an O(1) operation instead of O(N).
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // DP table (memo): 1D array because we only have 1 changing variable (the index).
        // -1 means Uncalculated, 0 means False, 1 means True.
        vector<int> memo(s.length(), -1);
        
        // Start the recursive check from the 0th index
        return wordBreak_rec(s, wordSet, 0, memo) == 1;
    }
};