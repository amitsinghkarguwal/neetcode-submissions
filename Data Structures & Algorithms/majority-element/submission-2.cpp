class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    
        // The majority element will always be at the middle index
        //the majority element is the element that appears more than ⌊n / 2⌋ times in the array.
        return nums[nums.size() / 2];
    }
};