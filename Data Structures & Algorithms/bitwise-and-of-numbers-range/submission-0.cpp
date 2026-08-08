class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // Erase the lowest set bit of 'right' until it's <= 'left'
        while (right > left) {
            right = right & (right - 1);
        }
        return right;
    }
};