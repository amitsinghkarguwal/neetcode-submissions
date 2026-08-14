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
    void inorder_rec(TreeNode* root,  vector<int> &result){
        if(root==nullptr) return;

        inorder_rec(root->left, result);
        result.push_back(root->val);
        inorder_rec(root->right, result);
    }


    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder_rec(root, result);
        return result;
    }
};