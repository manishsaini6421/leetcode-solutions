class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        int right = INT_MAX;
        if (j < n - 1)
            right = grid[i][j] + solve(i, j + 1, grid, dp);
        int down = INT_MAX;
        if (i < m - 1)
            down = grid[i][j] + solve(i + 1, j, grid, dp);

        return dp[i][j] = min(right, down);
    }

    int solveTab(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> curr(n,0);
        vector<int> next(n,0);
        next[n-1]=curr[n-1]=grid[m-1][n-1];

        

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int right = INT_MAX;
                if (j < n - 1)
                    right = grid[i][j] + curr[j + 1];
                int down = INT_MAX;
                if (i < m - 1)
                    down = grid[i][j] + next[j];

                if(!(i==m-1 && j==n-1))curr[j] = min(right, down);
            }
            next=curr;
        }
        return next[0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(0, 0, grid, dp);

        return solveTab(grid);
    }
};