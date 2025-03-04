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
    //height array
    int height[100001];
    // function to calculate heights of all substrees 
    int calHeight(TreeNode* root){
        if(root==NULL)return 0;
        int lef=calHeight(root->left);
        int rig=calHeight(root->right);
        height[root->val]=max(lef,rig);
        return max(lef,rig)+1;
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // array for storing height of tree if that index node is deleted 
        int newheight[100001];
        calHeight(root);
        // BFS queue
        queue<TreeNode*>q;
        q.push(root);
        // count of level
        int lev=0;
        while(!q.empty()){
            int n=q.size();
            // if only one node
            if(n==1){
                TreeNode* curr=q.front();
                q.pop();
                // store the level of upper tree as removing this node we'll not include this level so that's why level-1
                newheight[curr->val]=lev-1;
                lev++;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
                continue;
            }
            // calculate the nodes havng max and second max value
            int maxi=0,secmaxi=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                if(height[curr->val]>height[maxi]){
                    secmaxi=maxi;
                    maxi=curr->val;
                }
                else if(height[curr->val]>height[secmaxi]){
                    secmaxi=curr->val;
                }
                q.pop();
                q.push(curr);
            }
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                // node is max and then add level of 2nd max
                if(curr->val==maxi){
                    newheight[curr->val]=lev+height[secmaxi];
                }
                else newheight[curr->val]=lev+height[maxi];
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            lev++;
        }
        // store the ans
        for(int &i:queries){
            i=newheight[i];
        }
        return queries;
    }
};