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
    vector<int> v;
    void inorder_rec(TreeNode* root){
        if(root==nullptr) return;
        inorder_rec(root->left);
        v.push_back(root->val);
        inorder_rec(root->right);
    }

    bool isValidBST(TreeNode* root) {
        inorder_rec(root);
        if(v.size()==1) return true;
        int i=1;
        while(i<v.size()){
            if(v[i]<=v[i-1]) return false;
            i++;
        }

        return true;


    }
};