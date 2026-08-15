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

class Solution {
public:
    int flag=0;
    int balance_check(TreeNode* root){
        if(!root) return true;

        int a=balance_check(root->left);
        int b=balance_check(root->right);
        if(abs(a-b)>1) flag=1;
        return 1+max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        balance_check(root);
        return flag==0;
    }
};