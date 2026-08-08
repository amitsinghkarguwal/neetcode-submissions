#include <vector>
#include <algorithm> // Required for std::sort

using namespace std;

class Solution { 
public: 
    bool hasDuplicate(vector<int>& nums) { 
        int n = nums.size(); 
        if (n == 0 || n == 1) return false; 
        
        // FIX: Use std::sort instead of nums.sort()
        sort(nums.begin(), nums.end()); 
        
        for (int i = 1; i < n; i++) { 
            if (nums[i - 1] == nums[i]) return true; 
        } 
        return false; 
    } 
};

