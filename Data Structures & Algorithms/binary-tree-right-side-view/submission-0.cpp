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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};

        queue<TreeNode*> q;
        vector<int> v;

        q.push(root);
        q.push(nullptr);

        while(!q.empty()){
            TreeNode* abhi=q.front();
            q.pop();

            if(abhi==nullptr){
                if(!q.empty()){
                    q.push(nullptr);
                    continue;
                }
                else{
                    break;
                }
            }

            if(q.front()==nullptr){
                v.push_back(abhi->val);
            }


            if(abhi->left) q.push(abhi->left);
            if(abhi->right) q.push(abhi->right);
        }
        return v;
    }
};