class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        for (int i = 0; i < intervals.size(); ++i) {
            // Case 1: newInterval is strictly after the current interval
            if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            }
            // Case 2: newInterval is strictly before the current interval
            else if (newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                
                // Add all remaining intervals, as they will definitely not overlap
                for (int j = i; j < intervals.size(); ++j) {
                    res.push_back(intervals[j]);
                }
                return res; // We are completely done
            }
            // Case 3: Intervals overlap, so we merge them
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        
        // If we reach here, the newInterval is the very last interval to be added
        res.push_back(newInterval);
        
        return res;
    }
};