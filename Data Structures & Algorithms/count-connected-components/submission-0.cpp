class Solution {

private:

    void bfs(int idx, vector<vector<int>> &adj, vector<int> &visited){
        queue<int> q;
        q.push(idx);

        while(!q.empty()){
            int ele=q.front();
            q.pop();

            for(int i=0;i<adj[ele].size();i++){
                if(!visited[adj[ele][i]]) {
                    q.push(adj[ele][i]);
                    visited[adj[ele][i]]=true;
                }
            }
        }
    }

public:

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        //making a adj list
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }


        int no_of_components=0;
        vector<int> visited(n, false);

        //iterating over each adj outer index, and doing bfs on it if not visited
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i]=true;
                no_of_components++;
                bfs(i, adj, visited);
                }
            }
        return no_of_components;
    }
};
