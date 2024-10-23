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
    vector<vector<int>> levelOrder(TreeNode* root) {
         if(!root) return {};
        vector<vector<int>> v;

       

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            for(int i=0; i<n; i++){
                TreeNode *x=q.front();
                temp.push_back(x->val);
                q.pop();
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            v.push_back(temp);
        }
        return v;
    }
};