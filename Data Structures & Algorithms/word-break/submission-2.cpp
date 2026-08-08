#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int wordBreak_rec(const string& s, const unordered_set<string>& wordSet, int start_index, vector<int>& memo) {
        
        // 1. BASE CASE : reached the end
        if (start_index == s.length()) {
            return 1; 
        }
        
        if (memo[start_index] != -1) {
            return memo[start_index];
        }
        
        string current_word = "";
        for (int end_index = start_index; end_index < s.length(); end_index++) {
            
            current_word += s[end_index];
            
            if (wordSet.count(current_word)) {
                
                if (wordBreak_rec(s, wordSet, end_index + 1, memo) == 1) { //left_out string ke lie chalaya hai.
                    return memo[start_index] = 1; // Success! Cache and return.
                }
            }
        }
        
        return memo[start_index] = 0; 
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        // OPTIMIZATION: Convert the vector dictionary into a Hash Set. 
        // This makes checking O(1) operation instead of O(N).
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // DP table (memo): 1D array because we only have 1 changing variable (the index).
        vector<int> memo(s.length(), -1);
        
        return wordBreak_rec(s, wordSet, 0, memo) == 1;
    }
};