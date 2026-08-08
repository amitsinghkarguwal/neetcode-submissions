class Solution {
public:
    // This helper just checks if a standard string is a palindrome
    bool checkPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        // 1. Clean the string (if required by the prompt)
        string result;
        for(auto c: s){
            if(isalnum(c)) result += tolower(c);
        }
        
        int i = 0;
        int j = result.length() - 1;

        while (i < j) {
            if (result[i] != result[j]) {
                // MISMATCH FOUND. 
                // Check if skipping the left character (i+1) works
                // OR if skipping the right character (j-1) works.
                return checkPalindrome(result, i + 1, j) || checkPalindrome(result, i, j - 1);
            }
            i++;
            j--;
        }
        
        return true; 
    }
};