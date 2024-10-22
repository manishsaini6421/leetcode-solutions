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
    int maxLevelSum(TreeNode* root) {
        vector<pair<int,int>> v;
        queue<TreeNode*> q;
        q.push(root);
        int t=1;
        while(!q.empty()){
           int levelSum=0;
            int levelSize=q.size();
            for(int i=0; i<levelSize; i++){
                TreeNode* x=q.front();
                levelSum+=x->val;
                q.pop();
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
                
            }
           v.push_back({levelSum,t});
            t++;
        }
        int max=INT_MIN,res=0;
        for(auto val:v){
            if(val.first>max ){
                max=val.first;
                res=val.second;
            }
        }
        return res;

    }
};