#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // We add an extra row and column padded with 0s at the top and left.
        // This prevents out-of-bounds errors (like trying to access index -1)
        prefix.assign(rows + 1, vector<int>(cols + 1, 0));
        
        // Build the 2D Prefix Sum array
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                prefix[r + 1][c + 1] = matrix[r][c] 
                                     + prefix[r][c + 1] 
                                     + prefix[r + 1][c] 
                                     - prefix[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Use the inclusion-exclusion principle to get the region sum in O(1) time
        return prefix[row2 + 1][col2 + 1] 
             - prefix[row1][col2 + 1] 
             - prefix[row2 + 1][col1] 
             + prefix[row1][col1];
    }
};