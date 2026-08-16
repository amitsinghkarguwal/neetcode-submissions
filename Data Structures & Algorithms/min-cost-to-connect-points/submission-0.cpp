//prim's algorithm

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // Min-heap stores {edge_cost, point_index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        vector<bool> visited(n, false);
        
        // Start from point 0 with a cost of 0
        minHeap.push({0, 0});
        
        int totalCost = 0;
        int nodesConnected = 0;
        
        // We need to connect all 'n' nodes
        while (nodesConnected < n) {
            auto [cost, currNode] = minHeap.top();
            minHeap.pop();
            
            // If the node is already in our MST, skip it
            if (visited[currNode]) {
                continue;
            }
            
            // Add the node to our MST
            visited[currNode] = true;
            totalCost += cost;
            nodesConnected++;
            
            // Calculate distances from the newly added node to all unvisited nodes
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                if (!visited[nextNode]) {
                    // Manhattan distance formula
                    int dist = abs(points[currNode][0] - points[nextNode][0]) + 
                               abs(points[currNode][1] - points[nextNode][1]);
                    
                    minHeap.push({dist, nextNode});
                }
            }
        }
        
        return totalCost;
    }
};