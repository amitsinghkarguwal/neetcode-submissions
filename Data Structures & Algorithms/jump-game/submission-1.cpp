class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr_jump=0;
        int i=0;

        while(i<nums.size()-1){
            curr_jump=max(nums[i], curr_jump);
            if(curr_jump==0) return false;
            curr_jump--;
            i++;
        }

        return true;

    }
};
