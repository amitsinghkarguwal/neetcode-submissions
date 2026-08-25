class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr != nullptr || !s.empty()) {
            // Push all left nodes to the stack
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }

            // Backtrack to the node and process it
            curr = s.top();
            s.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }

        return result;
    }
};