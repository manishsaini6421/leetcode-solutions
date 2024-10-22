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

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> v;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            long long levelSum=0;
            int levelSize=q.size();
            for(int i=0; i<levelSize; i++){
                TreeNode* x=q.front();
                levelSum+=x->val;
                
                q.pop();
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            v.push_back(levelSum);
        }
        sort(v.begin(),v.end());
        for(auto val:v){
            cout<<val<<endl;
        }
        if(v.size()<k) return -1;
        return v[v.size()-k];
    }
};