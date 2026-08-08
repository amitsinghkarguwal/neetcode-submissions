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
            int num=q.front().first;
            int parent=q.front().second;
            q.pop();

            for(int i=0;i<adj[num].size();i++){

                //when we have cycle
                if(visited[adj[num][i]] && adj[num][i]!=parent){
                    return false;
                }


                if(adj[num][i]==parent){
                    continue;
                }

                visited[adj[num][i]]=true;
                q.push({adj[num][i], num});
            }

        }

        //for the hapening of differnet disconnected trees
        for(auto i : visited){
            if(i==false) return false;
        }

        return true;




    }
};
