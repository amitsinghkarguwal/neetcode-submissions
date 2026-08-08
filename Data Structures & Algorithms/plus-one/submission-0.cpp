#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // If it's not a 9, just add 1 and we are completely done.
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            digits[i] = 0;
        }
        

        digits.push_back(0);
        digits[0] = 1;
        
        return digits;
    }
};