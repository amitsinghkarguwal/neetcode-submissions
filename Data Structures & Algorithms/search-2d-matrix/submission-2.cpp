class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> matrix_condense;

        for(auto i: matrix){
            for(auto j: i){
                matrix_condense.push_back(j);
            }
        }

        int left=0;
        int right=matrix_condense.size()-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(matrix_condense[mid]==target){
                return true;
            }

            else if(target>matrix_condense[mid]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }

        return false;
    }
};
