#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // Create an array to store the rank of each character.
        // We use an array of size 26 because there are only lowercase English letters.
        int charRank[26];
        for (int i = 0; i < order.length(); ++i) {
            charRank[order[i] - 'a'] = i;
        }

        // Compare adjacent words
        for (int i = 0; i < words.size() - 1; ++i) {
            string word1 = words[i];
            string word2 = words[i + 1];
            bool foundDifference = false;
            
            // Compare characters of word1 and word2
            int minLength = min(word1.length(), word2.length());
            for (int j = 0; j < minLength; ++j) {
                if (word1[j] != word2[j]) {
                    // If the first differing character in word1 has a higher rank 
                    // than in word2, they are not sorted.
                    if (charRank[word1[j] - 'a'] > charRank[word2[j] - 'a']) {
                        return false;
                    }
                    // Difference found, and it is in the correct order.
                    // Stop checking this word pair.
                    foundDifference = true;
                    break; 
                }
            }

            // Edge Case: If no difference was found, but word1 is longer than word2
            // e.g., word1 = "apple", word2 = "app"
            if (!foundDifference && word1.length() > word2.length()) {
                return false;
            }
        }

        return true;
    }
};