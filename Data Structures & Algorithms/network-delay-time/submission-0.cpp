#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build the adjacency list
        // adj[u] = list of {v, weight}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }
        
        // Step 2: Set up Dijkstra's
        // Min-heap stores pairs of {cumulative_time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});
        
        // Keep track of visited nodes to avoid cycles and redundant work
        vector<bool> visited(n + 1, false);
        
        int timeNeeded = 0;
        int nodesVisited = 0;
        
        while (!minHeap.empty()) {
            auto [currTime, node] = minHeap.top();
            minHeap.pop();
            
            // If we've already found the shortest path to this node, skip it
            if (visited[node]) {
                continue;
            }
            
            // Mark as visited and update our metrics
            visited[node] = true;
            nodesVisited++;
            timeNeeded = max(timeNeeded, currTime);
            
            // Early exit if we've reached all nodes
            if (nodesVisited == n) {
                return timeNeeded;
            }
            
            // Push unvisited neighbors into the heap
            for (const auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int travelTime = neighbor.second;
                
                if (!visited[nextNode]) {
                    minHeap.push({currTime + travelTime, nextNode});
                }
            }
        }
        
        // If we exit the loop and haven't visited all nodes, some are unreachable
        return nodesVisited == n ? timeNeeded : -1;
    }
};