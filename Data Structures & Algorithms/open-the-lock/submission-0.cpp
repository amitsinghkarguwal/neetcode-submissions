class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Use a hash set for O(1) lookups
        unordered_set<string> dead_set(deadends.begin(), deadends.end());
        
        // Base cases
        if (dead_set.count("0000")) return -1;
        if (target == "0000") return 0;
        
        // Queue stores pairs of {current_combination, turns_taken}
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        
        // Visited set to avoid cycles. We can add "0000" right away.
        unordered_set<string> visited;
        visited.insert("0000");
        
        while (!q.empty()) {
            auto [curr, turns] = q.front();
            q.pop();
            
            // If we reached the target, return the number of turns
            if (curr == target) {
                return turns;
            }
            
            // Generate all 8 possible next combinations
            for (int i = 0; i < 4; ++i) {
                // d = -1 (decrement wheel), d = 1 (increment wheel)
                for (int d = -1; d <= 1; d += 2) {
                    string next_comb = curr;
                    
                    // Char math to handle wrap around (e.g., '9' -> '0' and '0' -> '9')
                    next_comb[i] = (next_comb[i] - '0' + d + 10) % 10 + '0';
                    
                    // If it's not a deadend and hasn't been visited, add to queue
                    if (!dead_set.count(next_comb) && !visited.count(next_comb)) {
                        visited.insert(next_comb);
                        q.push({next_comb, turns + 1});
                    }
                }
            }
        }
        
        return -1; // Target is unreachable
    }
};