class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Edge case: impossible to find two distinct indices with distance 0
        if (k == 0) return false;

        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            // 1. Add the current number to the window
            m[nums[i]]++;
            
            // 2. Check if we found a duplicate inside our window
            if (m[nums[i]] > 1) {
                return true;
            }
            
            // 3. If our window has reached size 'k', remove the oldest element
            // so the next iteration doesn't exceed the distance limit.
            if (i >= k) {
                m[nums[i - k]]--;
            }
        }

        return false;
    }
};