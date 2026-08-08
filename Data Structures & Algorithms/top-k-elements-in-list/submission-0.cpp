class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i: nums){
            m[i]++;
        }

        vector<int> result;

        vector<pair<int,int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
            });
        auto it=v.begin();
        

        while(k){
            result.push_back(it->first);
            k--;
            it++;
        }

        return result;
    }
};
