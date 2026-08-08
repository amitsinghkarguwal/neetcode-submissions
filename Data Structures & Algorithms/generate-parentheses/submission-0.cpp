class Solution {
public:
    vector<string> res;

    void backtrack(int open, int close, int n, string temp){
        //base condition
        if(temp.length()==2*n){
            res.push_back(temp);
            return;
        }

        if(open<n){
            backtrack(open+1 , close, n , temp+'(');
        }

        if(close<open){
            backtrack(open, close+1, n, temp+')');
        }
    }

    vector<string> generateParenthesis(int n) {
        string temp="";
        backtrack(0,0, n, temp);

        return res;
    }
};
