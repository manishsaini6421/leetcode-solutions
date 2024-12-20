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
   void reverse(TreeNode* leftChild,TreeNode* rightChild, int lavel){
    if(leftChild==NULL || rightChild==NULL)return;
    if(lavel%2==0){
        int temp=leftChild->val;
        leftChild->val=rightChild->val;
        rightChild->val=temp;

    }
    reverse(leftChild->left,rightChild->right,lavel+1);
    reverse(leftChild->right,rightChild->left,lavel+1);
   }
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse(root->left,root->right,0);
        return root;
    }
};