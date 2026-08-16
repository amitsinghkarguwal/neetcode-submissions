#include <vector>
#include <queue>
#include <cmath>
#include <array>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        // Min-heap to store {current_effort, row, col}
        // Using std::array<int, 3> is slightly faster and cleaner than vector<int>
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> minHeap;
        
        // Track the minimum effort required to reach each cell to avoid redundant work
        vector<vector<int>> minEffort(rows, vector<int>(cols, INT_MAX));
        
        // Start at top-left cell
        minHeap.push({0, 0, 0});
        minEffort[0][0] = 0;
        
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!minHeap.empty()) {
            auto [effort, r, c] = minHeap.top();
            minHeap.pop();
            
            // Because it's a min-heap, the first time we reach the target, it is guaranteed
            // to be via the path with the minimum possible effort.
            if (r == rows - 1 && c == cols - 1) {
                return effort;
            }
            
            // Optimization: If we already found a better path to this cell, skip it
            if (effort > minEffort[r][c]) {
                continue;
            }
            
            // Explore all 4 adjacent neighbors
            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                // Check boundaries
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    // The effort required to move to the neighbor is the maximum of:
                    // 1. The effort it took to get to the current cell
                    // 2. The height difference between the current cell and the neighbor
                    int nextEffort = max(effort, abs(heights[r][c] - heights[nr][nc]));
                    
                    // If this new path to the neighbor requires less effort than previously recorded,
                    // update our records and push it to the queue.
                    if (nextEffort < minEffort[nr][nc]) {
                        minEffort[nr][nc] = nextEffort;
                        minHeap.push({nextEffort, nr, nc});
                    }
                }
            }
        }
        
        return 0; // Fallback, should never be reached
    }
};