#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path; // Stores our current sequence of palindromes
        
        backtrack(s, 0, path, result);
        
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        // 1. BASE CASE: If our starting index has reached the end of the string,
        // we have successfully partitioned the entire string!
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        // 2. ITERATE: Try to form a palindrome from 'start' to 'i'
        for (int i = start; i < s.length(); i++) {
            
            // 3. CHECK: Is the current substring a palindrome?
            if (isPalindrome(s, start, i)) {
                
                // CHOOSE: Add this palindrome to our current path
                path.push_back(s.substr(start, i - start + 1));
                
                // EXPLORE: Recursively partition the REST of the string (from i + 1)
                backtrack(s, i + 1, path, result);
                
                // UN-CHOOSE (BACKTRACK): Remove the last added substring so we 
                // can try the next 'i' in our loop
                path.pop_back();
            }
        }
    }

    // Helper function to check if a substring is a palindrome
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};