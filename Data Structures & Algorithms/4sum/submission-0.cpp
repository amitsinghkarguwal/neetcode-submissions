#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // A quadruplet requires at least 4 numbers
        if (n < 4) return result;
        
        // Step 1: Sort the array to enable two-pointers and duplicate skipping
        sort(nums.begin(), nums.end());
        
        // Step 2: Fix the first number
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Step 3: Fix the second number
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                // Step 4: Two-pointer search for the remaining two numbers
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    // CAUTION: Cast to long long to prevent integer overflow!
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Move both pointers inward
                        left++;
                        right--;
                        
                        // Skip duplicates for the third number
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        
                        // Skip duplicates for the fourth number
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } 
                    else if (sum < target) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};