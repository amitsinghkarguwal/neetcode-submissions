#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        
        sort(projects.begin(), projects.end());
        
        priority_queue<int> max_heap;
        int ptr = 0;
        
        for (int i = 0; i < k; i++) {
            
            while (ptr < n && projects[ptr].first <= w) {
                max_heap.push(projects[ptr].second);
                ptr++;
            }
            
            if (max_heap.empty()) {
                break;
            }
            
            // Step 5: Greedily pick the most profitable project and update our capital
            w += max_heap.top();
            max_heap.pop();
        }
        
        return w;
    }
};