class Solution {
public:
    int longestConsecutive(vector<int>& n) {
        if(n.size()==0){
            return 0;
        }
        if(n.size()==1){
            return 1;
        }

        int curr_max=1;
        int maxi=1;
        
        set<int> s(n.begin(), n.end());
        vector<int> v(s.begin(), s.end());
        
        for(int i=0;i<(v.size()-1);i++){
            if(v[i]+1==v[i+1]){
                curr_max++;
            }
            else{
                maxi=max(maxi,curr_max);
                curr_max=1;
            }
        }

        return max(maxi, curr_max);
    }
};