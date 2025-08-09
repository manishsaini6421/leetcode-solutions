class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
        int m=grid.size();
        int n=grid[0].size();
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==m-1 && j==n-1)return grid[i][j];

        int right =INT_MAX;
        if(j<n-1)
            right=grid[i][j]+solve(i,j+1,grid,dp);
        int down=INT_MAX;
        if(i<m-1)
            down=grid[i][j]+solve(i+1,j,grid,dp);

        return dp[i][j]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,grid,dp);
    }
};