#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    // Max-Heap: Stores the smaller half of the numbers
    priority_queue<int> maxHeap; 
    
    // Min-Heap: Stores the larger half of the numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {
        // Initialization handled by default constructors
    }
    
    void addNum(int num) {
        // 1. Add to Max-Heap (Left) first
        maxHeap.push(num);
        
        // 2. Enforce Value Order: 
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // 3. Enforce Size Balance: 
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {

        if (maxHeap.size() > minHeap.size()) return maxHeap.top();

        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};