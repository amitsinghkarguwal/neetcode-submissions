class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<pair<int,int>> pq;
        vector<int> result;

        //pushing the starting window elements
        for(int i=0;i<k;i++){
            pq.push({nums[i], i});
        }

        result.push_back(pq.top().first);

        

        for(int i=k;i<nums.size();i++){


            pq.push({nums[i], i});


            while(pq.top().second<(i-k+1)){
                pq.pop();
            }

            result.push_back(pq.top().first);
        }

        return result;

    }
};
