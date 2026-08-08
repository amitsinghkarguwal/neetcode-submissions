class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set<int> s1;
        unordered_set<int> s2;
        unordered_set<int> s3;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if( s1.count(board[i][j]) ) return false;
                s1.insert(board[i][j]);
            }
            for(int k=0;k<9;k++){
                if(board[k][i]=='.') continue;
                if( s2.count(board[k][i]) ) return false;
                s2.insert(board[k][i]);
            }
            s1.clear();
            s2.clear();
        }

        for(int i=0;i<9;i+=3){
            for(int l=0;l<9;l+=3){
                for(int s=0;s<3;s++){
                    for(int t=0;t<3;t++){
                        if(board[i+s][l+t]=='.') continue;
                            if( s3.count(board[i+s][l+t]) ) return false;
                            s3.insert(board[i+s][l+t]);
                    }
                }
                s3.clear();
            }
        }

        return true;
    }
};
