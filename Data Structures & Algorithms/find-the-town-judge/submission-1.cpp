#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Base case: If there is only 1 person and no trust relationships,
        // they are the judge by default.
        if (n == 1) {
            return 1;
        }
        
        // Use a single array to track the net "trust score" of each person.
        // Array size is n + 1 because people are 1-indexed (1 to n).
        vector<int> trustScores(n + 1, 0);
        
        // Process each relationship
        for (const auto& relation : trust) {
            int a = relation[0]; // Person who trusts
            int b = relation[1]; // Person being trusted
            
            trustScores[a]--; // 'a' trusts someone, so they lose a point (can't be judge)
            trustScores[b]++; // 'b' is trusted, so they gain a point
        }
        
        // The town judge will be the only person with exactly n - 1 points.
        for (int i = 1; i <= n; i++) {
            if (trustScores[i] == n - 1) {
                return i;
            }
        }
        
        // If no one meets the criteria, return -1
        return -1;
    }
};