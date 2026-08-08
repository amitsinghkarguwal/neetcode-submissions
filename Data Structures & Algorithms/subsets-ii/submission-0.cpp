
class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;

    void backtrack(vector<int>& nums, int start) {
        res.push_back(subset);

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;

            subset.push_back(nums[i]);
            backtrack(nums, i + 1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Step 1: sort
        backtrack(nums, 0);
        return res;
    }
};
