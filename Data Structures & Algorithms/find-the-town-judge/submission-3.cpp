class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return n;

        vector<int> people_trusting(n+1, 0);

        for(auto i: trust){
            int second=i[1];
            int first=i[0];
            people_trusting[second]++;
            people_trusting[first]--;

        }

        for(int i=1;i<people_trusting.size();i++){
            if(people_trusting[i]==n-1) return i;
        }
        return -1;
    }
};