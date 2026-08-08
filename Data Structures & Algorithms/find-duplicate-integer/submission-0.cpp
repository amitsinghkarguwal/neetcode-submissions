class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //because the size of the array is n+1, and the numbers in the array is also from 1 to n, we can see here index as value here,
        int slow=nums[0];
        int fast=slow;

        do{
            slow=nums[slow];
            fast=nums[nums[fast]];

        }while(slow!=fast);

        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }

        return slow;
    }
};