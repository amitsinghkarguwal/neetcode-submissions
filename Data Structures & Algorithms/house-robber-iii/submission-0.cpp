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
    int rob(TreeNode* root) {
        vector<int> result = robSubtree(root);
        
        return max(result[0], result[1]);
    }

private:
    vector<int> robSubtree(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }

        vector<int> left = robSubtree(node->left);
        vector<int> right = robSubtree(node->right);
        
        int skip_node = max(left[0], left[1]) + max(right[0], right[1]);
        
        int rob_node = node->val + left[0] + right[0];
        
        return {skip_node, rob_node};
    }
};