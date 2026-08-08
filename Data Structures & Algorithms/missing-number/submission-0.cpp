#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Start the result at 'n' because the loop indices will only go up to n-1.
        int result = n; 
        
        for (int i = 0; i < n; i++) {
            // XOR the current index (the "checklist" number)
            // AND XOR the actual array value
            result ^= i ^ nums[i]; 
        }
        
        return result;
    }
};