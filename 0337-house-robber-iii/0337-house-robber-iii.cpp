/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, map<TreeNode*, int>& dp) {
        if (root == NULL)
            return 0;
        if (dp.count(root))
            return dp[root];
        int incll = 0, inclr = 0;
        if (root->left)
            incll = solve(root->left->left, dp) + solve(root->left->right, dp);
        if (root->right)
            inclr =
                solve(root->right->left, dp) + solve(root->right->right, dp);
        int incl = root->val + incll + inclr;
        int excl = solve(root->left, dp) + solve(root->right, dp);
        return dp[root] = max(incl, excl);
    }
    int rob(TreeNode* root) {
        map<TreeNode*, int> dp;
        return solve(root, dp);
    }
};