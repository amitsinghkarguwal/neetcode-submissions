//kushkal

class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;
        parent[rootY] = rootX;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // Stores {cost, u, v}
        vector<vector<int>> edges;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, i, j});
            }
        }
        
        // Sort edges by cost
        sort(edges.begin(), edges.end());
        
        UnionFind uf(n);
        int totalCost = 0;
        int edgesUsed = 0;
        
        for (const auto& edge : edges) {
            if (uf.unite(edge[1], edge[2])) {
                totalCost += edge[0];
                edgesUsed++;
                if (edgesUsed == n - 1) break;
            }
        }
        
        return totalCost;
    }
};