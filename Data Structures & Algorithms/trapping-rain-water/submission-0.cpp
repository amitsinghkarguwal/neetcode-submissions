class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height.size(),0);
        vector<int> right_max(height.size(),0);

        for(int i=1;i<height.size();i++){
            left_max[i]=max(left_max[i-1], height[i-1]);
        }

        for(int i=height.size()-2;i>-1;i--){
            right_max[i]=max(right_max[i+1], height[i+1]);
        }

        int trapped_water=0;
        for(int i=0;i<height.size();i++){
            int water_level;
            water_level=min(left_max[i], right_max[i])-height[i];
            trapped_water+=max(water_level, 0);
        }

        return trapped_water;
    }
};
