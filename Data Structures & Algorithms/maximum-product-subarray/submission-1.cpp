#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int current_max = nums[0];
        int current_min = nums[0];
        int global_max = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            
            // The Magic Trick: If the number is negative, our highest potential product will come from multiplying it with our lowest negative product!
            if (num < 0) {
                swap(current_max, current_min);
            }
            
            current_max = max(num, current_max * num);
            current_min = min(num, current_min * num);
            
            global_max = max(global_max, current_max);
        }
        
        return global_max;
    }
};