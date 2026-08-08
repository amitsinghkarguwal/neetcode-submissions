class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        string result;

        while(i<word1.length() && i<word2.length()){
            result+=word1[i];
            result+=word2[i];
            i++;
        }

        if(i!=word1.length()){
            result+=word1.substr(i);
        }

        if(i!=word2.length()){
            result+=word2.substr(i);
        }

        return result;
    }
};