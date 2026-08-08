#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty() || s.length() < t.length()) {
            return "";
        }

        // Frequency maps for characters in T and our current window
        unordered_map<char, int> countT;
        unordered_map<char, int> window;

        for (char c : t) {
            countT[c]++;
        }

        int have = 0;
        int need = countT.size(); // Number of unique characters we need

        // Variables to store the result: {start_index, length}
        int resStart = -1;
        int resLen = -1; 
        
        int left = 0;

        // Slide the right pointer across the string
        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            window[c]++;

            // If the current character is in T and we've reached the exact count needed
            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            // While the window is valid, try to shrink it from the left
            while (have == need) {
                // Update our result if this is the smallest valid window so far
                int currentWindowLen = right - left + 1;
                if (resLen == -1 || currentWindowLen < resLen) {
                    resStart = left;
                    resLen = currentWindowLen;
                }

                // Pop the leftmost character out of the window to shrink it
                char leftChar = s[left];
                window[leftChar]--;

                // If removing this character breaks our valid window condition
                if (countT.count(leftChar) && window[leftChar] < countT[leftChar]) {
                    have--;
                }
                
                left++; // Actually shrink the window
            }
        }

        return resLen == -1 ? "" : s.substr(resStart, resLen);
    }
};