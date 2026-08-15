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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Base case: if the tree is empty, return null
        if (!root) {
            return nullptr;
        }
        
        // 1 & 2. Process children first (Post-order traversal)
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        
        // 3. Process the current node
        // If it is a leaf AND its value equals the target, delete it
        if (!root->left && !root->right && root->val == target) {
            // Note: In competitive programming/LeetCode, we often just return nullptr 
            // without explicitly deleting the memory to save time, but in a real 
            // C++ application, you would `delete root;` here to prevent memory leaks.
            return nullptr;
        }
        
        // Return the unchanged node if it shouldn't be deleted
        return root;
    }
};