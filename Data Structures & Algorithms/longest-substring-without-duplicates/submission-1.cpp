class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.length()==0) return 0;
        if(s.length()==1) return 1;
        int max_length=1;
        int i=0,j=0;

        unordered_set<char> st;      
        while(j<s.length()){
            while(st.count(s[j])) {
            st.erase(s[i]);
            i++;
            }
            st.insert(s[j]);
            max_length=max(max_length, j-i+1);
            j++;

        }
        return max_length;
    }
};
