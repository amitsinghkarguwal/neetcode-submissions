#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> radiant, dire;
        
        // Populate the initial queues with indices
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        
        // Simulate the rounds until one party is entirely eliminated
        while (!radiant.empty() && !dire.empty()) {
            int r_idx = radiant.front();
            int d_idx = dire.front();
            
            radiant.pop();
            dire.pop();
            
            // The senator with the smaller index votes first
            if (r_idx < d_idx) {
                // Radiant wins this matchup, pushes back for the next round
                radiant.push(r_idx + n);
            } else {
                // Dire wins this matchup, pushes back for the next round
                dire.push(d_idx + n);
            }
        }
        
        return radiant.size() > dire.size() ? "Radiant" : "Dire";
    }
};