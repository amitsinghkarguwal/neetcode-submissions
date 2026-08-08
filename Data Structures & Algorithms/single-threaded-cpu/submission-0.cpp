class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        // Step 1: Augment the tasks with their original indices
        vector<vector<int>> sorted_tasks;
        for (int i = 0; i < n; i++) {
            sorted_tasks.push_back({tasks[i][0], tasks[i][1], i});
        }
        
        // Step 2: Sort chronologically by enqueueTime
        sort(sorted_tasks.begin(), sorted_tasks.end());
        
        // Step 3: Min-Heap to store {processingTime, original_index}
        // std::greater forces the priority_queue to act as a Min-Heap instead of a Max-Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> result;
        
        long long time = 0; 
        int i = 0;
        
        while (i < n || !pq.empty()) {
            
            // If the CPU is idle, time-travel to the next task's arrival time
            if (pq.empty() && time < sorted_tasks[i][0]) {
                time = sorted_tasks[i][0];
            }
            
            // Load all tasks that have arrived up to the current time
            while (i < n && sorted_tasks[i][0] <= time) {
                pq.push({sorted_tasks[i][1], sorted_tasks[i][2]});
                i++;
            }
            
            // Pop the shortest available task
            auto [procTime, index] = pq.top();
            pq.pop();
            
            time += procTime;
            result.push_back(index);
        }
        
        return result;
    }
};