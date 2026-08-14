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
    TreeNode* invertTree(TreeNode* root) {
        // Base case: if the tree is empty, return null
        if (root == nullptr) {
            return nullptr;
        }

        // 1. Swap the left and right children using a local temp variable
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // 2. Recursively call invertTree on the newly swapped left and right children
        invertTree(root->left);
        invertTree(root->right);

        // 3. Return the modified tree
        return root;
    }
};