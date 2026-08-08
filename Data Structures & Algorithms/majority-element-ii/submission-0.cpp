#include <unordered_map>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> result;
        int threshold = nums.size() / 3;
        
        for (int num : nums) {
            count[num]++;
            
            // As soon as a number crosses the threshold, add it.
            // (We check exactly equal to threshold + 1 to prevent adding duplicates)
            if (count[num] == threshold + 1) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};