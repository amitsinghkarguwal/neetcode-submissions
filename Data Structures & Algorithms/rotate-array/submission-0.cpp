class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int new_k=k%nums.size();
        
        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin()+new_k);
        reverse(nums.begin()+new_k, nums.end());
    }
};