class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Handle edge cases for empty matrices
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Treat the matrix as a flattened 1D array
        int left = 0;
        int right = (rows * cols) - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Convert 1D 'mid' index back to 2D matrix coordinates
            int row = mid / cols;
            int col = mid % cols;
            int midValue = matrix[row][col];
            
            // Standard binary search logic
            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};