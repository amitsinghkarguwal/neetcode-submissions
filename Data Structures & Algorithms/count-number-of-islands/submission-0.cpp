class Solution {
public:

    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited){

        queue<pair<int,int>> q;

        int n=grid.size();
        int m=grid[0].size();

        visited[row][col]=true;
        q.push({row, col});


        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            //traversing the neighbours


            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for(int i=0;i<4;i++){
                    int new_row=r+dr[i];
                    int new_col=c+dc[i];
                    if(new_row>=0 && new_row<n && new_col>=0 && new_col<m 
                    && grid[new_row][new_col]=='1' && !visited[new_row][new_col]){
                        visited[new_row][new_col]=true;
                        q.push({new_row, new_col});
                    }
                
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int col=grid[0].size();
        int island_count=0;

        vector<vector<bool>> visited(rows, vector<bool>(col, false));

        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){

                if(!visited[i][j] && grid[i][j]=='1'){
                    island_count++;
                    bfs(i, j, grid, visited);
                }

            }
        }

        return island_count;
        
    }
};
