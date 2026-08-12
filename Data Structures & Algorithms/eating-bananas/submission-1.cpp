class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        //beware the h>=piles.size();
        int left = 1;

        int right = 0;
        for (int pile : piles) {
            right = max(right, pile);
        }

        
        int result = right; //letting the maximum element be the result.
        
        while (left <= right) {
            int k = left + (right - left) / 2;
            
            long long total_hours = 0; 
            
            for (int pile : piles) {
                total_hours+=pile/k;
                if(pile%k!=0){
                    total_hours+=1;
                }
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