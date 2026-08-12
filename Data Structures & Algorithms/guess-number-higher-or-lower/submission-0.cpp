
class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = guess(mid);
            
            if (result == 0) {
                return mid;
            } else if (result == -1) {
                right = mid - 1; // Guess was too high
            } else {
                left = mid + 1;  // Guess was too low
            }
        }
        
        return -1;
    }
};