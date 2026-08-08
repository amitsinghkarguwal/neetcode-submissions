class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;

        for(auto &s: strs){
            vector<int> alp(26,0);
            for(auto c: s){
                alp[c-'a']++;
            }
            m[alp].push_back(s);
        }

        vector<vector<string>> result;
        for(auto &i: m){
            result.push_back(i.second);
        }
        return result;
    }
};
