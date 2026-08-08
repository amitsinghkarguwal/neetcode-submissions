class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,1);
        int post=1;

        // for filling from start
        for(int i=1;i<n;i++){
            result[i]=nums[i-1]*result[i-1];
        }

        //for filling from end
        for(int i=n-2;i>=0;i--){
            post=post*nums[i+1];
            result[i]=result[i]*post;
        }

        return result;
        


    }
};
