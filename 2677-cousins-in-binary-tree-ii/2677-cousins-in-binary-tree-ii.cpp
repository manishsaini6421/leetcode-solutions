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
    void dfs(vector<TreeNode*> arr){
        if(arr.empty()) return;
        int sum=0;
        for(auto node:arr){
            if(node->left)sum+=node->left->val;
            if(node->right)sum+=node->right->val;
        }

        vector<TreeNode*> childArr;
        
        for(auto node:arr){
            int currSum=0;
            if(node->left)currSum+=node->left->val;
            if(node->right)currSum+=node->right->val;

            if(node->left)
            {
                node->left->val=sum-currSum;
                childArr.push_back(node->left);
            }
            if(node->right)
            {
                node->right->val=sum-currSum;
                childArr.push_back(node->right);
            }   
            
        }
        dfs(childArr);

    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val=0;
        dfs(vector<TreeNode*> {root});
        return root;

    }
};