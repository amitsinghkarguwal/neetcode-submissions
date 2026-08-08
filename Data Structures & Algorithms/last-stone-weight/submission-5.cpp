class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size()>1){
            int first_stone=pq.top();
            pq.pop();
            int second_stone=pq.top();
            pq.pop();
            if(first_stone>second_stone) pq.push(first_stone-second_stone);
        }

        if(pq.size()==0) return 0;
        return pq.top();
    }
};
