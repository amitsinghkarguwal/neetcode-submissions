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

        for (int i = 0; i < n; i++) {
            inorder_map[inorder[i]] = i;
        }
        
        return build(preorder, 0, n - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int left, int right) {

        if (left > right) {
            return nullptr;
        }

        int root_value = preorder[preorder_index++];

        TreeNode* root = new TreeNode(root_value);

        int mid = inorder_map[root_value];

        root->left = build(preorder, left, mid - 1);     
        root->right = build(preorder, mid + 1, right);

        return root;
    }

    
};