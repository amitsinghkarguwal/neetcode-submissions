class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> alphabet(26,0);
        int left=0;
        int max_freq=0;
        int max_length=0;

        for(int right=0;right<s.length();right++){
            alphabet[s[right]-'A']++;
            max_freq=max(max_freq, alphabet[s[right]-'A']);

            while((right-left+1)-max_freq>k){
                alphabet[s[left]-'A']--;
                left++;
            }
            max_length=max(max_length, right-left+1);
        }
        return max_length;


    }
};
