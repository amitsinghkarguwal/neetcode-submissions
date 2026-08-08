class Solution {
public:
    vector<vector<int>> result;

    void sum_rec(int idx, vector<int>& nums, int target, int curr_sum, vector<int>& temp){
        // Base Case 1: Target Exceeded
        if(curr_sum > target){
            return;
        }

        // Base Case 2: Target Met
        if(curr_sum == target){
            result.push_back(temp);
            return;
        }

        // Base Case 3: Out of Bounds
        if(idx >= nums.size()){ 
            return;
        }

        // --- Branch 1: INCLUDE the current number ---
        temp.push_back(nums[idx]);
        curr_sum += nums[idx];
        sum_rec(idx + 1, nums, target, curr_sum, temp);
        
        // --- BACKTRACK ---
        temp.pop_back();
        curr_sum -= nums[idx];

        // --- THE FILTERING LOGIC ---
        // If we decided NOT to use nums[idx], we should skip all identical numbers 
        // right next to it so we don't generate duplicate combinations.
        while(idx + 1 < nums.size() && nums[idx] == nums[idx + 1]){
            idx++; 
        }

        // --- Branch 2: EXCLUDE the current number ---
        sum_rec(idx + 1, nums, target, curr_sum, temp);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Step 1: SORT the array so duplicates sit next to each other
        sort(candidates.begin(), candidates.end());

        int curr_sum = 0;
        vector<int> temp;
        int idx = 0;

        // Step 2: Pass the sorted 'candidates' directly into the recursion
        sum_rec(idx, candidates, target, curr_sum, temp);
    
        return result;
    }
};