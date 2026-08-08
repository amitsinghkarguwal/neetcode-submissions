class Solution {
public:

    void bfs(int row, int col, vector<vector<int>> &heights, vector<vector<bool>> &visited){

        queue<pair<int,int>> q;

        int n=heights.size();
        int m=heights[0].size();

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
                    && heights[new_row][new_col]>=heights[r][c] && !visited[new_row][new_col]){
                        visited[new_row][new_col]=true;
                        q.push({new_row, new_col});
                    }
                
            }

        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows=heights.size();
        int col=heights[0].size();


        vector<vector<bool>> visited_pacific(rows, vector<bool>(col, false));
        vector<vector<bool>> visited_atlantic(rows, vector<bool>(col, false));

        //for pacific
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if (i == 0 || j == 0 ) {
                    if (!visited_pacific[i][j]) {
                        bfs(i, j, heights, visited_pacific);
                    }
                }
                if(i == rows - 1 || j == col - 1){
                    if(!visited_atlantic[i][j]){
                        bfs(i, j, heights, visited_atlantic);
                    }
                }
            }
        }

        vector<vector<int>> result_matrix;

        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(visited_atlantic[i][j] && visited_pacific[i][j]){
                    result_matrix.push_back({i,j});
                }
            }
        }

        return result_matrix;
        
    }
};
