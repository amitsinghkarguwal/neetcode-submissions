#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> num_stack;
        stack<string> str_stack;
        
        string current_str = "";
        int current_num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                // Handle multi-digit numbers (e.g., "12[a]")
                current_num = current_num * 10 + (c - '0');
            } 
            else if (isalpha(c)) {
                // Build the current string
                current_str += c;
            } 
            else if (c == '[') {
                // Pause! Save current state to stacks and reset for the inner bracket
                num_stack.push(current_num);
                str_stack.push(current_str);
                
                current_num = 0;
                current_str = "";
            } 
            else if (c == ']') {
                // Resolve! 
                // 1. Get the multiplier
                int k = num_stack.top();
                num_stack.pop();
                
                // 2. Get the string we had put on hold
                string prev_str = str_stack.top();
                str_stack.pop();
                
                // 3. Multiply the current string k times and append it to the held string
                for (int i = 0; i < k; i++) {
                    prev_str += current_str;
                }
                
                // 4. Our merged string becomes the new current string
                current_str = prev_str;
            }
        }
        
        return current_str;
    }
};