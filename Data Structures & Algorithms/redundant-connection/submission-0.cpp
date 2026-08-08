class Solution {
private:
    vector<int> parent;
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); 
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        // 1-based indexing, so size is n + 1
        parent.resize(n + 1);
        
        // Initially, every node is its own parent
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            int rootU = find(u);
            int rootV = find(v);
            
            if (rootU == rootV) {
                return edge; 
            }
            
            // Otherwise, union the two sets together
            parent[rootU] = rootV;
        }
        
        return {}; // Should not be reached based on problem constraints
    }
};