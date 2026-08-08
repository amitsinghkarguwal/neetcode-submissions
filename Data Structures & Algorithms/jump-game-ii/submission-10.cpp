//using Greedy Approach  


class Solution {
public:
    int jump(vector<int>& nums) {
        int count=0;
        int max_jump=0;
        int right=0;

        for(int i=0;i<nums.size()-1;i++){

            max_jump=max(max_jump, i+nums[i]);

            if(right==i){
                right=max_jump;
                count++;
            }
        }

        return count;
    }
};
