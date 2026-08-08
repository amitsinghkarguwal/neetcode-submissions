class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        
        // Keep shifting right until the numbers are equal.
        // This finds the common binary prefix.
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        
        // Shift the common prefix back to the left to append the zeros
        return left << shift;
    }
};