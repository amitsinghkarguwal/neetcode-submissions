class Solution {
public:
    int result=0;
    int height(TreeNode* root){
        if(root==nullptr) return 0;

        int left=height(root->left);
        int right=height(root->right);

        result=max(result, left+right+1);

        return 1+max(left,right);
    } 

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return result-1; //because yaha par edges count kar rahe hai, nodes hoti toh return result;
    }
};