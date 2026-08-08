class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> result;

        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size()-2;i++){
            int target=-nums[i];

            unordered_set<int> s;
            for(int j=i+1;j<nums.size();j++){

                //if target-j is in the set s
                if(s.count(target-nums[j])){
                    result.insert({nums[i], target-nums[j], nums[j]});
                }

                s.insert(nums[j]);

            }
        }

        vector<vector<int>> result2(result.begin(), result.end());

        return result2;
    }
};
