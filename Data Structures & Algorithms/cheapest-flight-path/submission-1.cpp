#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        
        vector<int> minCost(n, 1e9);
        minCost[src] = 0;
        
        // Queue stores {current_node, cumulative_cost}
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        int stops = 0;
        
        // Process level by level up to k stops
        while (!q.empty() && stops <= k) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [node, cost] = q.front();
                q.pop();
                
                for (auto& [neighbor, price] : adj[node]) {
                    int nextCost = cost + price;
                    // Only push to the queue if we found a strictly cheaper way
                    if (nextCost < minCost[neighbor]) {
                        minCost[neighbor] = nextCost;
                        q.push({neighbor, nextCost});
                    }
                }
            }
            stops++;
        }
        
        return minCost[dst] == 1e9 ? -1 : minCost[dst];
    }
};