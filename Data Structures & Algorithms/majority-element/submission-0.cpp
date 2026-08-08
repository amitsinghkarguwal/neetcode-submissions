#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            // If the count drops to zero, we pick a new candidate
            if (count == 0) {
                candidate = num;
            }
            
            // If the current number matches our candidate, vote UP
            // If it's a different number, vote DOWN
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        // The surviving candidate is guaranteed to be the majority element
        return candidate;
    }
};