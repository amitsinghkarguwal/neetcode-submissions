class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0; // Minimum possible open left brackets
        int maxOpen = 0; // Maximum possible open left brackets
        
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // c == '*'
                minOpen--; // Treat as ')'
                maxOpen++; // Treat as '('
            }
            
            // If the absolute maximum possible open brackets drops below zero,
            // we've seen too many ')' to ever recover.
            if (maxOpen < 0) {
                return false;
            }
            
            // We can never have fewer than zero open brackets. 
            // If minOpen drops below zero, it means we forced a '*' to be a ')' 
            // when we didn't need to. Just treat it as empty instead.
            if (minOpen < 0) {
                minOpen = 0;
            }
        }
        
        // If it's possible to have 0 open brackets at the end, it's valid.
        return minOpen == 0;
    }
};