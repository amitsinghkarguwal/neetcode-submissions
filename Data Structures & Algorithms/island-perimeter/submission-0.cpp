class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // If we land on an island cell
                if (grid[r][c] == 1) {
                    // Assume it's completely isolated first
                    perimeter += 4;
                    
                    // Check if there is land ABOVE it
                    if (r > 0 && grid[r - 1][c] == 1) {
                        perimeter -= 2; // Subtract the shared horizontal edge
                    }
                    
                    // Check if there is land to the LEFT of it
                    if (c > 0 && grid[r][c - 1] == 1) {
                        perimeter -= 2; // Subtract the shared vertical edge
                    }
                }
            }
        }
        
        return perimeter;
    }
};