/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// this question is also considered as DP question, since we are storing the highest diameter in result.

class Solution {
public:
    int result=0;
    int height(TreeNode* root){
        if(root==nullptr) return 0;

        int left=height(root->left);
        int right=height(root->right);

        int temp=1+max(left,right);
        result=max(result, left+right+1);
        return temp;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return result-1;
    }
};