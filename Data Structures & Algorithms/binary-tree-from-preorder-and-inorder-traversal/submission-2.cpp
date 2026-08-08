/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int preorder_index = 0;
    unordered_map<int, int> inorder_map;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n= preorder.size();

        // Build the Hash Map for O(1) lookups
        for (int i = 0; i < n; i++) {
            inorder_map[inorder[i]] = i;
        }
        
        // Step 2: Start the recursion with the full inorder array boundaries
        return build(preorder, 0, n - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int left, int right) {
        // Base Case: If there are no elements to construct the tree
        if (left > right) {
            return nullptr;
        }

        int root_value = preorder[preorder_index++];

        TreeNode* root = new TreeNode(root_value);

        // Step 2: Find where this root splits the inorder array
        int mid = inorder_map[root_value];

        // Step 3: Recurse! 
        // Build the left subtree using elements STRICTLY to the left of 'mid'
        root->left = build(preorder, left, mid - 1);
        
        // Build the right subtree using elements STRICTLY to the right of 'mid'
        root->right = build(preorder, mid + 1, right);

        // Return the fully constructed root node
        return root;
    }
};