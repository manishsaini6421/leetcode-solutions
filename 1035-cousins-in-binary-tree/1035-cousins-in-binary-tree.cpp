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
    void dfs(TreeNode* root, int x, int y,TreeNode* &parent1,TreeNode* &parent2,int &level1,int& level2,int level){
        if(!root)return;
        level++;
        if(root->left && root->left->val==x){
            parent1=root;
            level1=level;
        }
        else if(root->left && root->left->val==y)
        {
            parent2=root;
            level2=level;
        }
        if(root->right && root->right->val==x)
        {
            parent1=root;
            level1=level;
        }
        else if(root->right && root->right->val==y)
        {
            parent2=root;
            level2=level;
        }
        if(root->left)dfs(root->left,x, y,parent1,parent2,level1,level2,level);
       if(root->right) dfs(root->right,x, y,parent1,parent2,level1,level2,level);

    }
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* parent1;
        TreeNode* parent2;
        int level1=0,level2=0;
        dfs(root,x, y,parent1,parent2,level1,level2,0);
        if(level1==level2 && parent1!=parent2) return true;
        return false;
    }
};