class Solution {
    // Memoization map: maps a starting index to a list of valid sentence suffixes
    unordered_map<int, vector<string>> memo;
    // Hash set for O(1) dictionary lookups
    unordered_set<string> wordSet;
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Populate the hash set
        for (const string& word : wordDict) {
            wordSet.insert(word);
        }
        
        // Start DFS from index 0
        return backtrack(s, 0);
    }
    
private:
    vector<string> backtrack(const string& s, int start) {
        // If we've already solved this suffix, return the cached result
        if (memo.count(start)) {
            return memo[start];
        }
        
        vector<string> validSentences;
        
        // Base case: we reached the end of the string successfully
        if (start == s.length()) {
            validSentences.push_back("");
            return validSentences;
        }
        
        // Try every possible end index for the first word of this suffix
        for (int end = start + 1; end <= s.length(); ++end) {
            string word = s.substr(start, end - start);
            
            // If the prefix is a valid word, recursively process the rest
            if (wordSet.count(word)) {
                vector<string> nextSentences = backtrack(s, end);
                
                // Append the current word to all sentences returned by the suffix
                for (const string& sentence : nextSentences) {
                    if (sentence.empty()) {
                        validSentences.push_back(word); // Last word in the string
                    } else {
                        validSentences.push_back(word + " " + sentence);
                    }
                }
            }
        }
        
        // Cache the result before returning
        memo[start] = validSentences;
        return validSentences;
    }
};