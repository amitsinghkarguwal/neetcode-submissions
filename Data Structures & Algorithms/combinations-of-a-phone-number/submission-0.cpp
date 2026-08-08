#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // 1. Edge Case: If the input is empty, return an empty array
        if (digits.empty()) return {};
        
        vector<string> result;
        
        string current_path = "";
        
        // 2. The Phone Dictionary: Map digits 0-9 to their letters
        // Index 2 maps to "abc", Index 3 maps to "def", etc.
        vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        // Start the recursive journey at index 0 of the digits string
        backtrack(digits, 0, current_path, keypad, result);
        
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& current_path, const vector<string>& keypad, vector<string>& result) {
        // 1. BASE CASE: If our index reaches the length of the digits string, 
        // we have formed a complete word!
        if (index == digits.length()) {
            result.push_back(current_path);
            return;
        }

        // 2. Look up the letters for the current digit
        // (Convert the char '2' into the integer 2 by subtracting '0')
        string letters = keypad[digits[index] - '0'];

        // 3. ITERATE through the possible letters for this digit
        for (char letter : letters) {
            
            // CHOOSE: Add the letter to our string
            current_path.push_back(letter);
            
            // EXPLORE: Move to the NEXT digit in the input string
            backtrack(digits, index + 1, current_path, keypad, result);
            
            // UN-CHOOSE (BACKTRACK): Remove the letter so we can try the next one
            current_path.pop_back();
        }
    }
};