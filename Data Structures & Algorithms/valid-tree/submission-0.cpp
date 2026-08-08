class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto it: edges){
            int first=it[0];
            int second=it[1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }

        vector<bool> visited(n,false);

        queue<pair<int,int>> q;

        q.push({0,-1});
        visited[0]=true;

        while(!q.empty()){
            int num = q.front().first;
            int parent = q.front().second;
            q.pop();

            // Using a range-based for loop makes it much easier to read
            for(int neighbor : adj[num]){
                // If we haven't visited this neighbor, mark it and queue it
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push({neighbor, num});
                } 
                // If we HAVE visited it, and it's NOT the parent, it's a cycle
                else if (neighbor != parent) {
                    return false;
                }
                // If it HAS been visited, but it IS the parent, we do absolutely nothing.
            }
        }

        //for the hapening of differnet disconnected trees
        for(auto i : visited){
            if(i==false) return false;
        }

        return true;




    }
};
