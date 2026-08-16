#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Step 1: Build the Graph
        // Adjacency list: node -> list of {neighbor, weight}
        unordered_map<string, vector<pair<string, double>>> adj;
        
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }
        
        // Step 2: Process each query using BFS
        vector<double> results;
        for (const auto& query : queries) {
            results.push_back(bfs(query[0], query[1], adj));
        }
        
        return results;
    }

private:
    double bfs(const string& start, const string& target, unordered_map<string, vector<pair<string, double>>>& adj) {
        // If either the start or target node doesn't exist in our graph, it's unresolvable.
        if (adj.find(start) == adj.end() || adj.find(target) == adj.end()) {
            return -1.0;
        }
        
        // Queue stores pairs of {current_node, cumulative_product}
        queue<pair<string, double>> q;
        unordered_set<string> visited;
        
        q.push({start, 1.0});
        visited.insert(start);
        
        while (!q.empty()) {
            auto [currNode, currProduct] = q.front();
            q.pop();
            
            // If we've reached the target node, return the accumulated product
            if (currNode == target) {
                return currProduct;
            }
            
            // Explore neighbors
            for (const auto& neighbor : adj[currNode]) {
                string nextNode = neighbor.first;
                double weight = neighbor.second;
                
                if (visited.find(nextNode) == visited.end()) {
                    visited.insert(nextNode);
                    q.push({nextNode, currProduct * weight});
                }
            }
        }
        
        // If the queue empties and we never reached the target, no path exists.
        return -1.0;
    }
};