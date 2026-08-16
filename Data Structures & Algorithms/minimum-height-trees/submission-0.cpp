#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Base case: if there is only one node, it is the root of the MHT
        if (n == 1) return {0};
        
        // Build the adjacency list and keep track of each node's degree
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        // Initialize the queue with all leaf nodes (degree == 1)
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }
        
        // Trim leaves layer by layer until 1 or 2 nodes remain
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int leavesCount = leaves.size();
            remainingNodes -= leavesCount;
            
            // Process all leaves in the current layer
            for (int i = 0; i < leavesCount; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                
                // Remove the leaf by decrementing the degree of its neighbors
                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    // If the neighbor becomes a leaf, add it to the queue for the next layer
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        
        // The remaining nodes in the queue are the centroids
        vector<int> mhtRoots;
        while (!leaves.empty()) {
            mhtRoots.push_back(leaves.front());
            leaves.pop();
        }
        
        return mhtRoots;
    }
};