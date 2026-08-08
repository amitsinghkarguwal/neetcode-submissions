#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        // Initialize an empty N x N board filled with '.'
        vector<string> board(n, string(n, '.'));
        
        // Arrays to keep track of which lines are under attack
        vector<int> cols(n, 0);
        vector<int> diag1(2 * n - 1, 0); // \ diagonal: row - col + (n - 1)
        vector<int> diag2(2 * n - 1, 0); // / diagonal: row + col
        
        // Start placing queens from row 0
        backtrack(0, n, board, ans, cols, diag1, diag2);
        
        return ans;
    }
    
private:
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& ans, 
                   vector<int>& cols, vector<int>& diag1, vector<int>& diag2) {
                       
        // 1. BASE CASE: If we reached row 'N', we successfully placed all queens!
        if (row == n) {
            ans.push_back(board);
            return;
        }
        
        // 2. ITERATE through every column in the current row
        for (int col = 0; col < n; col++) {
            
            // 3. PRUNING/CHECK: Is this cell under attack?
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) {
                continue; // Not safe! Skip to the next column.
            }
            
            // CHOOSE: Place the queen and mark her attack paths as dangerous
            board[row][col] = 'Q';
            cols[col] = 1;
            diag1[row - col + n - 1] = 1;
            diag2[row + col] = 1;
            
            // EXPLORE: Move down to the next row
            backtrack(row + 1, n, board, ans, cols, diag1, diag2);
            
            // UN-CHOOSE (BACKTRACK): Remove the queen and clear her attack paths
            board[row][col] = '.';
            cols[col] = 0;
            diag1[row - col + n - 1] = 0;
            diag2[row + col] = 0;
        }
    }
};