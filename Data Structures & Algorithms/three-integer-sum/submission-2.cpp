class Solution {
public:

    // vector<vector<int>> threeSum(vector<int>& nums) {

    //     //set covert hojata hai vector mein, but unordered_set nahi hota hai, hence using set here
    //     set<vector<int>> result;

    //     sort(nums.begin(), nums.end());

    //     for(int i=0;i<nums.size()-2;i++){
    //         int target=-nums[i];

    //         unordered_set<int> s;
    //         for(int j=i+1;j<nums.size();j++){

    //             //if target-j is in the set s
    //             if(s.count(target-nums[j])){
    //                 result.insert({nums[i], target-nums[j], nums[j]});
    //             }

    //             s.insert(nums[j]);

    //         }
    //     }

    //     vector<vector<int>> result2(result.begin(), result.end());

    //     return result2;
    // }


    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sort first!

        for(int i = 0; i < nums.size(); i++) {
            // Skip duplicates for the first number
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if(sum < 0) {
                    left++; // We need a bigger number
                } 
                else if(sum > 0) {
                    right--; // We need a smaller number
                } 
                else {
                    // We found exactly 0!
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // Skip duplicates for the second number to avoid duplicate triplets
                    while(left < right && nums[left] == nums[left-1]) {
                        left++;
                    }
                }
            }
        }
        return result;
    }





};
