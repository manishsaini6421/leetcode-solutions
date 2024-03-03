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
  
    int countNodes(TreeNode* root) {
       
        if(root==NULL) return 0;
        
            if(root->left==NULL && root->right==NULL){
                return 1;
            }
            else{
                int a=countNodes(root->left);
               int b=countNodes(root->right);
                int c=a+b+1;
               return c;
            }

        
        
    }
     
        
};