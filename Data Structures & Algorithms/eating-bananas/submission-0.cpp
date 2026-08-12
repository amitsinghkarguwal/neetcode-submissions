class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;

        int right = 0;
        for (int pile : piles) {
            right = max(right, pile);
        }
        
        int result = right;
        
        while (left <= right) {
            int k = left + (right - left) / 2;
            
            long long total_hours = 0; 
            
            for (int pile : piles) {
                total_hours += (pile + k - 1) / k;
            }
            
            if (total_hours <= h) {
                result = k;
                right = k - 1;
            } else {
                left = k + 1;
            }
        }
        
        return result;
    }
};