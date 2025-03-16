class Solution {
public:
    int solve(vector<int>& obstacles, int currLane, int pos) {
        int n = obstacles.size() - 1;
        if (pos == n)
            return 0;
        if (currLane != obstacles[pos + 1]) {
            return solve(obstacles, currLane, pos + 1);
        }

        int ans = INT_MAX;
        for (int newLane = 1; newLane <= 3; newLane++) {
            if (currLane != newLane && obstacles[pos] != newLane)
                ans = min(ans, 1 + solve(obstacles, newLane, pos));
        }

        return ans;
    }

    int solveMem(vector<int>& obstacles, int currLane, int pos,
                 vector<vector<int>>& dp) {
        int n = obstacles.size() - 1;
        if (pos == n)
            return 0;
        if (dp[currLane][pos] != -1)
            return dp[currLane][pos];

        if (currLane != obstacles[pos + 1]) {
            return solveMem(obstacles, currLane, pos + 1, dp);
        }

        int ans = INT_MAX;
        for (int newLane = 1; newLane <= 3; newLane++) {
            if (currLane != newLane && obstacles[pos] != newLane)
                ans = min(ans, 1 + solveMem(obstacles, newLane, pos, dp));
        }

        return dp[currLane][pos] = ans;
    }

    int solveTab(vector<int>& obstacles) {

        int n = obstacles.size() - 1;
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));

        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int pos = n - 1; pos >= 0; pos--) {
            for (int currLane = 1; currLane <= 3; currLane++) {
                if (currLane != obstacles[pos + 1]) {
                    dp[currLane][pos] = dp[currLane][pos + 1];
                } else {
                    int ans = 1e9;
                    for (int newLane = 1; newLane <= 3; newLane++) {
                        if (currLane != newLane && obstacles[pos] != newLane)
                             //Catch
                            ans = min(ans, 1 + dp[newLane][pos+1]);
                    }
                    dp[currLane][pos] = ans;
                }
            }
        }

        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }

    int solveOpt(vector<int>& obstacles) {

        int n = obstacles.size() - 1;
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));

        vector<int> next(4,0);
        vector<int> curr(4,1e9);
        

        for (int pos = n - 1; pos >= 0; pos--) {
            for (int currLane = 1; currLane <= 3; currLane++) {
                if (currLane != obstacles[pos + 1]) {
                    curr[currLane] = next[currLane];
                } else {
                    int ans = 1e9;
                    for (int newLane = 1; newLane <= 3; newLane++) {
                        if (currLane != newLane && obstacles[pos] != newLane)
                             //Catch
                            ans = min(ans, 1 + next[newLane]);
                    }
                    curr[currLane] = ans;
                }
            }
            next=curr;
        }

        return min(curr[2], min(1 + curr[1], 1 + curr[3]));
    }

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();

        // return solve(obstacles, 2, 0);

        // vector<vector<int>> dp(4, vector<int>(n, -1));
        // return solveMem(obstacles, 2, 0, dp);

        //return solveTab(obstacles);

        return solveOpt(obstacles);
    }
};