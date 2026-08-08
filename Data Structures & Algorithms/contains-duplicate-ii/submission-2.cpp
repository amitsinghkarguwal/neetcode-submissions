class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {
            // If the element is already in the set, we found a match!
            if (window.count(nums[i])) {
                return true;
            }
            
            // Otherwise, add it to our window
            window.insert(nums[i]);
            
            // Keep the window size strictly at 'k'
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        return false;
    }
};