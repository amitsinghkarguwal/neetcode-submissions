#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            // Force the 1-indexed system into a 0-indexed system
            columnNumber--; 
            
            // Calculate the current character and append it
            char current_char = 'A' + (columnNumber % 26);
            result += current_char;
            
            // Shift down to the next base-26 digit
            columnNumber /= 26;
        }
        
        // The characters were extracted from right to left, so reverse them
        reverse(result.begin(), result.end());
        
        return result;
    }
};