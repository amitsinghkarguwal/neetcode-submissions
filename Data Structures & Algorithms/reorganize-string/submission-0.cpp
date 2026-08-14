#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        int max_freq = 0;
        char max_char;
        
        // Step 1: Count frequencies and find the champion character
        for (char c : s) {
            freq[c - 'a']++;
            if (freq[c - 'a'] > max_freq) {
                max_freq = freq[c - 'a'];
                max_char = c;
            }
        }
        
        int n = s.length();
        
        // Step 2: Pigeonhole Principle check
        if (max_freq > (n + 1) / 2) {
            return "";
        }
        
        // Step 3: Pre-allocate the result string
        string result = s; 
        int index = 0;
        
        // Step 4: Exhaust the absolute most frequent character on EVEN indices
        while (freq[max_char - 'a'] > 0) {
            result[index] = max_char;
            index += 2;
            freq[max_char - 'a']--;
        }
        
        // Step 5: Fill in the remaining characters
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                // If we ran out of even indices, loop back around to the first odd index
                if (index >= n) {
                    index = 1;
                }
                
                result[index] = i + 'a';
                index += 2;
                freq[i]--;
            }
        }
        
        return result;
    }
};