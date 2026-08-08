class Solution {
public:

    vector<vector<int>> result;

    void sum_rec(int idx, vector<int>& nums, int target, int curr_sum, vector<int>& temp){
        if(curr_sum>target){
            return;
        }

        if(curr_sum==target){
            result.push_back(temp);
            return;
        }

        if(idx>=nums.size()){ 
            return;
        }

        temp.push_back(nums[idx]);
        curr_sum+=nums[idx];
        sum_rec(idx, nums, target, curr_sum, temp);
        temp.pop_back();
        curr_sum-=nums[idx];
        sum_rec(idx+1, nums, target, curr_sum, temp);

    }


    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        

        int curr_sum=0;
        vector<int> temp;

        int idx=0;

        sum_rec(idx, nums, target, curr_sum, temp );

        return result;



    }
};
