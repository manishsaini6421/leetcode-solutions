class Solution {
public:
    int solve(vector<int>& obstacles, int i, int lane,vector<vector<int>> &dp) {
        if (i == obstacles.size() - 1)
            return 0;
        if(dp[i][lane]!=-1)return dp[i][lane];
        if (lane != obstacles[i + 1]) {
            return solve(obstacles, i + 1, lane,dp);
        }

        int ans = INT_MAX;
        if (lane == 1) {
            if (obstacles[i] != 2)
                ans = min(ans, 1 + solve(obstacles, i, 2,dp));
            if (obstacles[i] != 3)
                ans = min(ans, 1 + solve(obstacles, i, 3,dp));
        } else if (lane == 2) {
            if (obstacles[i] != 1)
                ans = min(ans, 1 + solve(obstacles, i, 1,dp));
            if (obstacles[i] != 3)
                ans = min(ans, 1 + solve(obstacles, i, 3,dp));
        } else if (lane == 3) {
            if (obstacles[i] != 1)
                ans = min(ans, 1 + solve(obstacles, i, 1,dp));
            if (obstacles[i] != 2)
                ans = min(ans, 1 + solve(obstacles, i, 2,dp));
        }
        return dp[i][lane]=ans;
    }
    int minSideJumps(vector<int>& obstacles) { 
        int n=obstacles.size();
        vector<vector<int>> dp(n,vector<int>(4,-1)); 
        return solve(obstacles, 0, 2,dp); 
        }
};