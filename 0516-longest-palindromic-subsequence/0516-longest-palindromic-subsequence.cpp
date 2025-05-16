class Solution {
public:
    int solve(string& s, int i, int j) {
        if (i == j)
            return 1;
        if (i > j)
            return 0;

        int ans = 0;
        if (s[i] == s[j]) {
            ans = 2 + solve(s, i + 1, j - 1);
        } else {
            ans = max(solve(s, i + 1, j), solve(s, i, j - 1));
        }
        return ans;
    }

    int solveMem(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i == j)
            return 1;
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (s[i] == s[j]) {
            ans = 2 + solveMem(s, i + 1, j - 1, dp);
        } else {
            ans = max(solveMem(s, i + 1, j, dp), solveMem(s, i, j - 1, dp));
        }
        return dp[i][j] = ans;
    }

    int solveTab(string& s) {

        int n = s.size();
        if (n == 1)
            return 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                int ans = 0;
                if(j-1>=0){
                if (s[i] == s[j]) {
                    ans = 2 + dp[i + 1][j - 1];
                } else {
                    ans = max(dp[i + 1][j], dp[i][j - 1]);
                }
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n - 1];
    }
    int longestPalindromeSubseq(string s) {
        // return solve(s,0,s.size()-1);

        // int n = s.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solveMem(s, 0, n - 1, dp);

        return solveTab(s);
    }
};