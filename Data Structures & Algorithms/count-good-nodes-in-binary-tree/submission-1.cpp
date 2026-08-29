class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int good_count = 0;
        
        // Queue stores pairs of {current_node, max_value_in_path_so_far}
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while (!q.empty()) {
            // Extract the node and the max value seen on its specific path
            auto [node, max_so_far] = q.front();
            q.pop();

            // Is this a "good" node?
            if (node->val >= max_so_far) {
                good_count++;
            }

            // Calculate the new max to pass down to the children
            int new_max = max(max_so_far, node->val);

            // Push children into the queue along with the updated max
            if (node->left != nullptr) {
                q.push({node->left, new_max});
            }
            if (node->right != nullptr) {
                q.push({node->right, new_max});
            }
        }

        return good_count;
    }
};