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
    void dfs_rec(TreeNode* root, int max, int &ans){
        if(root==nullptr) return;
        if(max<=root->val){
            max=root->val;
            ans+=1;
        }
        dfs_rec(root->left, max, ans);
        dfs_rec(root->right, max, ans);

    }

    int goodNodes(TreeNode* root) {
        int ans=0;
        int max=root->val;
        dfs_rec(root, max, ans);
        return ans;
    }
};