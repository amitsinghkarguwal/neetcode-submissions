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

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for(int i=0;i<4;i++){
                    int new_row=r+dr[i];
                    int new_col=c+dc[i];
                    if(new_row>=0 && new_row<n && new_col>=0 && new_col<m 
                    && grid[new_row][new_col]=='O' && !visited[new_row][new_col]){
                        visited[new_row][new_col]=true;
                        q.push({new_row, new_col});
                    }
                
            }

        }
    }

void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(!visited[i][j] && board[i][j]=='O'){
                        bfs(i,j, board, visited);
                    }
                }
            }
        }

        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }

            }
        }
        
    }
};
