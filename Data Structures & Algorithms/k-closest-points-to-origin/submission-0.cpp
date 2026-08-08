#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, vector<int>>> maxHeap;
        
        for (const auto& point : points) {
            // Calculate x^2 + y^2
            int dist = point[0] * point[0] + point[1] * point[1];
            maxHeap.push({dist, point});
            
            // If we exceed size K, kick out the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return result;
    }
};