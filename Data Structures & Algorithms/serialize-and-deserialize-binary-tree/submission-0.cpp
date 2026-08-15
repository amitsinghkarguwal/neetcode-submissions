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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }

private:
    void serializeHelper(TreeNode* node, ostringstream& out) {
        if (!node) {
            out << "N "; // 'N' represents null, followed by a space delimiter
            return;
        }
        
        // Pre-order: Root -> Left -> Right
        out << node->val << " ";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }

    TreeNode* deserializeHelper(istringstream& in) {
        string val;
        in >> val; // Read the next token separated by space
        
        if (val == "N") {
            return nullptr;
        }
        
        // Create the root node for this sub-tree
        TreeNode* node = new TreeNode(stoi(val));
        
        // Recursively build the left and right sub-trees
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        
        return node;
    }
};