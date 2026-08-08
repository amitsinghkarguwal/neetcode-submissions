class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area=0;
        int left=0;
        int right=heights.size()-1;

        while(left<right){
            int curr_area=min(heights[left],heights[right])*(right-left);
            max_area=max(max_area, curr_area);

            if(heights[left]>heights[right]) right--;
            else left++;
        }

        return max_area;
    }
};
