// industry-standard O(1) space technique
// (O(N^2) Time, O(1) Space)

#include <string>

using namespace std;

class Solution {
private:
    // Helper function that expands outward and returns the count of valid palindromes
    int expandAroundCenter(const string& s, int left, int right) {
        int count = 0;
        
        // Keep expanding as long as pointers are in bounds AND characters match
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++; 
            left--;  
            right++; 
        }
        
        return count;
    }

public:
    int countSubstrings(string s) {
        int total_palindromes = 0;
        
        // Iterate through all characters to act as centers
        for (int i = 0; i < s.length(); i++) {
            
            // 1. Odd-length centers (center is exactly on s[i])
            // e.g., left and right both start at 'b' in "aba"
            total_palindromes += expandAroundCenter(s, i, i);
            
            // 2. Even-length centers (center is BETWEEN s[i] and s[i+1])
            // e.g., left starts at 'b', right starts at the second 'b' in "abba"
            total_palindromes += expandAroundCenter(s, i, i + 1);
        }
        
        return total_palindromes;
    }
};


