class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        int first_stone, second_stone;

        while(pq.size()>1){
            first_stone=pq.top();
            pq.pop();
            second_stone=pq.top();
            pq.pop();
            if(first_stone>second_stone) pq.push(first_stone-second_stone);
        }

        if(pq.size()==0) return 0;
        return pq.top();
    }
};
