class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int i=0,j=0;
        int global_min=100001;
        int sum=0;

        while(j<nums.size() && i<=j){

            sum+=nums[j];

            while(sum>=target && i<=j){
                global_min=min(global_min,j-i+1);
                sum=sum-nums[i];
                i++;

            }
            
            if(sum<target) j++;


        }

        if(global_min==100001) return 0;
        return global_min;

    }
};