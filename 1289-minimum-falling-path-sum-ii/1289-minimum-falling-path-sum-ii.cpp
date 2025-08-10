class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix,vector<vector<int>> &dp){
        int n=matrix.size();
        if(i==n-1)return matrix[i][j];

        if(dp[i][j]!=INT_MAX)return dp[i][j];

        int ans=INT_MAX;
        
        for(int k=0; k<n; k++){
            if(j!=k)
                ans=min(ans,solve(i+1,k,matrix,dp));
        }
        
        return dp[i][j]=matrix[i][j]+ans;      
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
         int n=grid.size();
        int ans=INT_MAX;

        vector<vector<int>> dp(n,vector<int> (n,INT_MAX)); //Not intilising with zero because it can be a answer

        for(int j=0; j<n; j++){
            ans=min(ans,solve(0,j,grid,dp));
        }
        return ans;
    }
};