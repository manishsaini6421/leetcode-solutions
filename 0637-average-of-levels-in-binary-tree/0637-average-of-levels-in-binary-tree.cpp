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
    int lavels(TreeNode* root){
        if(!root)return -1;
        if(!root->left && !root->right)return 0;

        int x=1+lavels(root->left);
        int y=1+lavels(root->right);

        return max(x,y);
    }
    void bfs(TreeNode* root,vector<vector<int>> &v,int lavel){
        if(!root)return;
        v[lavel].push_back(root->val);
        bfs(root->left,v,lavel+1);
        bfs(root->right,v,lavel+1);


    }
    vector<double> averageOfLevels(TreeNode* root) {

        int n=lavels(root);
        vector<vector<int>> v(n+1);
        bfs(root,v,0);

        vector<double> ans;

        for(int i=0; i<=n; i++){
            double sum=0;
            for(auto num:v[i]){
                sum+=num;
            }
            cout<<sum<<" ";
            ans.push_back(sum/v[i].size());
        }
        return ans;
    }
};