class KthLargest {
private:
    //class banne bola hai toh, queue and k uske apne variables banenge.
    // priority_queue<int> max_heap; max_heap initialization. 
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto n: nums){
            add(n);
        }
    }
    
    int add(int val) {
        min_heap.push(val);

        if(min_heap.size()>k){
            min_heap.pop();
        }

        return min_heap.top();
    }
};
