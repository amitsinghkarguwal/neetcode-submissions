class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n,1);
        vector<int> post(n,1);
        vector<int> result(n,1);

        // for filling pre 
        for(int i=1;i<n;i++){
            pre[i]=nums[i-1]*pre[i-1];
        }

        //for filling post
        for(int i=n-2;i>=0;i--){
            post[i]=nums[i+1]*post[i+1];
        }

        for(auto i=0;i<n;i++){
            result[i]=pre[i]*post[i];
        }

        return result;
        


    }
};
