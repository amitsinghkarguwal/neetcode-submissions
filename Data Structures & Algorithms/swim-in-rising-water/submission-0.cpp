using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Min-heap to store {max_elevation_so_far, row, col}
        // std::array is slightly faster and lighter than std::vector here
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> minHeap;
        
        // Keep track of visited cells to prevent cycles and redundant work
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Start at top-left
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!minHeap.empty()) {
            auto [time, r, c] = minHeap.top();
            minHeap.pop();
            
            // If we reached the bottom-right corner, return the time
            if (r == n - 1 && c == n - 1) {
                return time;
            }
            
            // Explore all 4 adjacent neighbors
            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                // Check grid boundaries and if the cell was already visited
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true; // Mark visited upon pushing to the queue
                    
                    // The time required to get to the neighbor is the maximum of 
                    // the path time so far and the neighbor's inherent elevation
                    int nextTime = max(time, grid[nr][nc]);
                    minHeap.push({nextTime, nr, nc});
                }
            }
        }
        
        return 0; // Fallback, should not be reached for valid grids
    }
};