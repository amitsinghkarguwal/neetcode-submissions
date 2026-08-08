#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;

    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {

        if (dp[i][j] != 0) {
            return dp[i][j];
        }

        int max_path = 1; // Every cell is a path of at least length 1 (itself)

        // 2. EXPLORE: Try all 4 directions
        for (auto& dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];

            // BOUNDARY & INCREASING CHECK:
            // Is the neighbor inside the grid AND strictly greater than us?
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                max_path = max(max_path, 1 + dfs(matrix, x, y, dp));
            }
        }

        return dp[i][j] = max_path;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        m = matrix.size();
        n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int global_max = 0;

        // We MUST try starting a path from every single cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                global_max = max(global_max, dfs(matrix, i, j, dp));
            }
        }

        return global_max;
    }
};