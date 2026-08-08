//if the array is not sorted, here given it is sorted, so go for two pointer approach
//by default hota hota hai ye
//priority_queue evaluates pairs by looking at the first number, and if there is a tie, it looks at the second number.

#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int, int>> max_heap;

        for (int i = 0; i < arr.size(); i++) {
            int dist = abs(arr[i] - x);
            
            max_heap.push({dist, arr[i]});
            
            if (max_heap.size() > k) {
                max_heap.pop();
            }
        }

        // Extract the surviving 'k' elements
        vector<int> result;

        while (!max_heap.empty()) {
            result.push_back(max_heap.top().second);
            max_heap.pop();
        }

        sort(result.begin(), result.end());
        
        return result;
    }
};