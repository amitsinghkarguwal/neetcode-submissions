#include <vector>
#include <queue>

using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        // Process the initial array through our stream logic
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        // 2. If we have more than 'k' elements, kick out the smallest one
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        
        // 3. The top of the min-heap is our Kth largest element
        return minHeap.top();
    }
};

