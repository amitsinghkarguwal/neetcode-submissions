#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // If the array is empty, there is no common prefix
        if (strs.empty()) return "";

        // Loop through the characters of the first string
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            
            // Compare this character with the same index in all other strings
            for (int j = 1; j < strs.size(); j++) {
                // If we reach the end of another string OR find a character mismatch
                if (i == strs[j].length() || strs[j][i] != c) {
                    // Return the substring of the first string up to the mismatch
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};