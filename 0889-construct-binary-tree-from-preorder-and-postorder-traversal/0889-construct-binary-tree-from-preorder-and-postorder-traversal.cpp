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
    TreeNode* tree(vector<int>& preorder,vector<int>& postorder,int &preIndex,unordered_map<int,int> &postIndex,int left,int right){
        if(preIndex>=preorder.size() || left>right)return NULL;

        TreeNode *node=new TreeNode(preorder[preIndex++]);
        
        if(preIndex<preorder.size()){
            int splitIndex=postIndex[preorder[preIndex]];
            if(splitIndex<=right){
                node->left=tree(preorder,postorder,preIndex,postIndex,left,splitIndex);
            node->right=tree(preorder,postorder,preIndex,postIndex,splitIndex,right-1);
            }
            
        }
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> postIndex;
        for(int i=0; i<postorder.size(); i++){
            postIndex[postorder[i]]=i;
        }
        int preIndex=0;
     return tree(preorder,postorder,preIndex,postIndex,0,postorder.size()-1);
    }
};