class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int i=nums.size()-1;
        while(i>-1){
            if(s.count(nums[i])){
                return true;
            }
            s.insert(nums[i]);
            i--;
        }
        return false;

        // unordered_set<int> s;
        // for(auto i: nums){
        //     if(s.count(i)){
        //         return true;
        //     }
        //     s.insert(i);
        // }
        // return false;
    }
};