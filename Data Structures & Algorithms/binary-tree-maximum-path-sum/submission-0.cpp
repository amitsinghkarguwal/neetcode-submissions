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
    int maxSum; // Global variable to store the maximum path sum found

public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        calculateMaxGain(root);
        return maxSum;
    }

private:
    int calculateMaxGain(TreeNode* node) {
        if (!node) return 0;
        
        // Post-order traversal: recursively calculate the max gain from children.
        // If a child's path sum is negative, we ignore it by taking max(..., 0).
        int leftGain = max(calculateMaxGain(node->left), 0);
        int rightGain = max(calculateMaxGain(node->right), 0);
        
        // 1. The "Arch": the max path sum that peaks at the current node.
        // We update our global maxSum if this new arch is better.
        int currentArchSum = node->val + leftGain + rightGain;
        maxSum = max(maxSum, currentArchSum);
        
        // 2. The "Branch": what this node can contribute to its parent.
        // It can only offer its own value plus the best single path down one side.
        return node->val + max(leftGain, rightGain);
    }
};