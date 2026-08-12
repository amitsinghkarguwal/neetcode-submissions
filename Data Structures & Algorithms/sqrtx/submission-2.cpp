class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        
        int left = 1;
        int right = x/2; //for 2 its valid, rest ke lie 1/2 se bhi kam aata hai.
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (mid == x / mid) {
                return mid;
            } else if (mid > x / mid) {
                right = mid - 1;
            } else {
                result = mid; // This might be the truncated answer, save it!
                left = mid + 1;
            }
        }
        
        return result;
    }
};