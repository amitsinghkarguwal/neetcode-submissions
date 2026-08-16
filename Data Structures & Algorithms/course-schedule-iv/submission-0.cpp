#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Build the adjacency list for the directed graph
        unordered_map<int, vector<int>> adj;
        for (const auto& p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }
        
        // 2D boolean array to store if course i is a prerequisite of course j
        vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses, false));
        
        // Run BFS from every course to find all its indirect/direct requirements
        for (int i = 0; i < numCourses; ++i) {
            queue<int> q;
            q.push(i);
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                for (int neighbor : adj[curr]) {
                    // If we haven't already marked it as reachable from 'i'
                    if (!isReachable[i][neighbor]) {
                        isReachable[i][neighbor] = true;
                        q.push(neighbor); // Push to queue to explore its neighbors
                    }
                }
            }
        }
        
        // Process queries in O(1) time each
        vector<bool> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            ans.push_back(isReachable[q[0]][q[1]]);
        }
        
        return ans;
    }
};