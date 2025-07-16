class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int i, int j,
              vector<vector<int>>& dp) {
                int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        

        if (i == m - 1 && j == n - 1) {
                return 1;
            
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = 0;
        if (j < n - 1 && obstacleGrid[i][j + 1] == 0) {
            right = solve(obstacleGrid, i, j + 1, dp);
        }
        int down = 0;
        if (i < m - 1 && obstacleGrid[i + 1][j] == 0) {
            down = solve(obstacleGrid, i + 1, j, dp);
        }
        return dp[i][j] = right + down;
    }
    int solveTab(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1]==1)
            return 0;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        dp[m-1][n-1]=((obstacleGrid[m-1][n-1]==0)?1:0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int right = 0;
                if (j < n - 1 && obstacleGrid[i][j + 1] == 0) {
                    right = dp[i][j + 1];
                }
                int down = 0;
                if (i < m - 1 && obstacleGrid[i + 1][j] == 0) {
                    down = dp[i + 1][j];
                }
                dp[i][j] = right + down;
            }
        }
        return dp[0][0];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, 0, 0, dp);

        //return solveTab(obstacleGrid);
    }
};