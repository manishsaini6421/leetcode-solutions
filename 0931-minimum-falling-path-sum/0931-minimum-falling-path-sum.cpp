class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix,vector<vector<int>> &dp){
        int m=matrix.size();
        int n=matrix[0].size();
        if(i==m-1)return matrix[i][j];

        if(dp[i][j]!=INT_MAX)return dp[i][j];

        int down=solve(i+1,j,matrix,dp);
        int leftDig=INT_MAX;
        if(j>0)
            leftDig=solve(i+1,j-1,matrix,dp);
        int rightDig=INT_MAX;
        if(j<n-1)
            rightDig=solve(i+1,j+1,matrix,dp);  

        return dp[i][j]=matrix[i][j]+min(down,min(leftDig,rightDig));      
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=INT_MAX;

        vector<vector<int>> dp(m,vector<int> (n,INT_MAX));
        for(int j=0; j<n; j++){
            ans=min(ans,solve(0,j,matrix,dp));
        }
        return ans;
    }
};