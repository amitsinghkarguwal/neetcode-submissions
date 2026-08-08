//mast question hai
// max_money_at_current_house = max(money_from_previous_house, 
//                                  money_from_till_2_houses_chhod_ke + current_house_value)

class Solution {
public:

    int rob_rec(vector<int>& nums, int n, vector<int>& dp ){

        if(n==0) return 0;

        if(n==1) return nums[n-1];

        if(dp[n]!=-1){
            return dp[n];
        }

        return dp[n]=max(rob_rec(nums, n-1, dp), rob_rec(nums, n-2, dp) + nums[n-1]);


    }
    int rob(vector<int>& nums) {

        if(nums.size()==1) return nums[0];

        vector<int> nums1(nums.begin()+1, nums.end());
        vector<int> nums2(nums.begin(), nums.end()-1);

        int n=nums1.size();

        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);

        return max(rob_rec(nums1, n, dp1), rob_rec(nums2, n,dp2));


    }


};
