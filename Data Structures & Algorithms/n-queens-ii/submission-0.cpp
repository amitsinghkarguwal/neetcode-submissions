class Solution {
public:
    int totalNQueens(int n) {
        int solutions = 0;
        
        // Trackers for columns and the two diagonals
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false); // Positive diagonals: row + col
        vector<bool> diag2(2 * n - 1, false); // Negative diagonals: row - col + (n - 1)
        
        backtrack(0, n, cols, diag1, diag2, solutions);
        
        return solutions;
    }

private:
    void backtrack(int row, int n, vector<bool>& cols, vector<bool>& diag1, 
                   vector<bool>& diag2, int& solutions) {
        
        // Base case: If we successfully placed a queen in every row
        if (row == n) {
            solutions++;
            return;
        }
        
        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++) {
            int d1 = row + col;
            int d2 = row - col + (n - 1);
            
            // If the cell is under attack, prune this branch
            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }
            
            // Choose: Mark the column and diagonals as under attack
            cols[col] = diag1[d1] = diag2[d2] = true;
            
            // Explore: Move to the next row
            backtrack(row + 1, n, cols, diag1, diag2, solutions);
            
            // Un-choose (Backtrack): Remove the queen and unmark the attack zones
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};