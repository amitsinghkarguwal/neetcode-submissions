class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return backtrack(nums, 0, 0);
    }

private:
    int backtrack(const vector<int>& nums, int index, int currentXOR) {
        if (index == nums.size()) {
            return currentXOR;
        }
        
        int include = backtrack(nums, index + 1, currentXOR ^ nums[index]);
        
        int exclude = backtrack(nums, index + 1, currentXOR);
        
        return include + exclude;
    }
};