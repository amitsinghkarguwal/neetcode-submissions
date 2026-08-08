class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int path = 1;

        while(!q.empty()){
            int levelSize = q.size(); 
            
            for(int i = 0; i < levelSize; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int d = 0; d < 4; d++){
                    int new_row = r + dr[d];
                    int new_col = c + dc[d];

                    if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n 
                       && grid[new_row][new_col] == INT_MAX) {
                        
                        grid[new_row][new_col] = path; // Update the grid directly
                        q.push({new_row, new_col});
                    }
                }
            }
            path++;
        }
    }
};