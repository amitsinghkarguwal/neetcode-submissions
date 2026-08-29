class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root==nullptr) return {}; // return result by putting it above, and {{}}, means creates a 2D vector that contains one empty 1D vector inside of it.

        vector<vector<int>> result;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int n=q.size();
            vector<int> inner_vector;

            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                int key=curr->val;
                inner_vector.push_back(key);

                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);
            }

            result.push_back(inner_vector);

        }


        return result;
    }
};
