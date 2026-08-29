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