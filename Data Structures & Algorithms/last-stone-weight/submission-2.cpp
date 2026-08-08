class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i: stones){
            pq.push(i);
        }



        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();

            if(pq.size()==0 && a==b) return 0;

            if(a>b){
                pq.push(a-b);
            }
            if(a<b){
                pq.push(b-a);
            }
        }

        return pq.top();
    }
};
