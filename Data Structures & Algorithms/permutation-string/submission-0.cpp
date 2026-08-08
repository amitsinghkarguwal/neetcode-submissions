class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> alpha1(26,0);
        for(auto c: s1){
            alpha1[c-'a']++;
        }

        int left=0;
        int right=s1.length()-1;

        for(right;right<s2.length();right++){
            vector<int> alpha2(26,0);
            int i=left;
            for(i;i<=right;i++){
                alpha2[s2[i]-'a']++;
            }
            if(alpha1==alpha2) return true;
            left++;
        }

        return false;
    }
};
