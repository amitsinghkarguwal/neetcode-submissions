class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalSum = 0;
        for (int match : matchsticks) {
            totalSum += match;
        }
        
        // If the total sum is not divisible by 4, we can't make a square
        if (totalSum % 4 != 0 || matchsticks.empty()) {
            return false;
        }
        
        int targetSide = totalSum / 4;
        vector<int> sides(4, 0);
        
        // PRUNING 1: Sort descending to try fitting the largest sticks first.
        // This makes the algorithm fail faster if a configuration is invalid.
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        return backtrack(matchsticks, sides, 0, targetSide);
    }

private:
    bool backtrack(const vector<int>& matchsticks, vector<int>& sides, int index, int target) {
        // Base case: we have placed all matchsticks
        if (index == matchsticks.size()) {
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
        }
        
        for (int i = 0; i < 4; i++) {
            // Check if placing the current matchstick exceeds the target length
            if (sides[i] + matchsticks[index] > target) {
                continue;
            }
            
            // PRUNING 2: If this side has the same length as the previous side, 
            // and we already failed to build a valid square using the previous side, 
            // we will fail here too. Skip redundant work.
            if (i > 0 && sides[i] == sides[i - 1]) {
                continue;
            }
            
            // Choose
            sides[i] += matchsticks[index];
            
            // Explore
            if (backtrack(matchsticks, sides, index + 1, target)) {
                return true;
            }
            
            // Un-choose (Backtrack)
            sides[i] -= matchsticks[index];
        }
        
        return false;
    }
};