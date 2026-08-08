class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        // Define our 4 boundaries
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        // Loop until the boundaries cross each other
        while (top <= bottom && left <= right) {
            
            // 1. Traverse Right (along the top boundary)
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++; // Shrink the top boundary down

            // 2. Traverse Down (along the right boundary)
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--; // Shrink the right boundary left

            // 3. Traverse Left (along the bottom boundary)
            // We must check if top <= bottom again, because the top boundary 
            // might have crossed the bottom boundary in step 1!
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--; // Shrink the bottom boundary up
            }

            // 4. Traverse Up (along the left boundary)
            // We must check if left <= right again for the same reason.
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Shrink the left boundary right
            }
        }

        return result;
    }
};