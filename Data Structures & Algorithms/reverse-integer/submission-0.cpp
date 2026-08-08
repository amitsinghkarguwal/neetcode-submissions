class Solution {
public:
    int reverse(int x) {
        int result = 0;
        
        while (x != 0) {
            // Step 1: Pop the rightmost digit
            int pop = x % 10;
            x /= 10;
            
            // Step 2 & 3: Check for overflow/underflow BEFORE it happens
            // INT_MAX is 2147483647
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) {
                return 0;
            }
            // INT_MIN is -2147483648
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) {
                return 0;
            }
            
            // Step 4: Push the digit onto the result
            result = result * 10 + pop;
        }
        
        return result;
    }
};