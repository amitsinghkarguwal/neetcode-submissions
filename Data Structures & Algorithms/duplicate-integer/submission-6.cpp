class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i : nums){
            if(m[i]){
                return true;
            }
            m[i]++;
        }
        return false;
    }
};