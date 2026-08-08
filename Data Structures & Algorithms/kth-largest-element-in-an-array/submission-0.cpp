#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-Heap declaration
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            
            // Keep the heap strictly at size K
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // The top element is the Kth largest
        return minHeap.top();
    }
};