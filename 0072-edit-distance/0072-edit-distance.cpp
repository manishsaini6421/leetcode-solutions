class Solution {
public:
    int solve(int i, int j, string& word1, string& word2) {

        if (i == word1.size())
            return word2.size() - j;
        if (j == word2.size())
            return word1.size() - i;

        int ans = 0;
        if (word1[i] == word2[j]) {
            ans = solve(i + 1, j + 1, word1, word2);
        } else {
            ans = 1 + min(solve(i + 1, j + 1, word1, word2),
                          min(solve(i + 1, j, word1, word2),
                              solve(i, j + 1, word1, word2)));
        }
        return ans;
    }

    int solveMem(int i, int j, string& word1, string& word2,
                 vector<vector<int>>& dp) {

        if (i == word1.size())
            return word2.size() - j;
        if (j == word2.size())
            return word1.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (word1[i] == word2[j]) {
            ans = solveMem(i + 1, j + 1, word1, word2, dp);
        } else {
            ans = 1 + min(solveMem(i + 1, j + 1, word1, word2, dp),
                          min(solveMem(i + 1, j, word1, word2, dp),
                              solveMem(i, j + 1, word1, word2, dp)));
        }
        return dp[i][j] = ans;
    }

    int solveTab(string& word1, string& word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == m)
                    dp[m][j] = n - j;
                if (j == n)
                    dp[i][n] = m - i;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int ans = 0;
                if (word1[i] == word2[j]) {
                    ans = dp[i + 1][j + 1];
                } else {
                    ans = 1 + min(dp[i + 1][j + 1],
                                  min(dp[i + 1][j], dp[i][j + 1]));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int solveTabOpt(string& word1, string& word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for (int j = 0; j <= n; j++) {
            next[j] = n - j;
        }

        for (int i = m - 1; i >= 0; i--) {
            curr[n]=m-i;
            for (int j = n - 1; j >= 0; j--) {
                int ans = 0;
                if (word1[i] == word2[j]) {
                    ans = next[j + 1];
                } else {
                    ans = 1 + min(next[j + 1], min(next[j], curr[j + 1]));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
    int minDistance(string word1, string word2) {
        // return solve(0, 0, word1, word2);

        // int m = word1.size();
        // int n = word2.size();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        // return solveMem(0, 0, word1, word2, dp);

        // return solveTab(word1,word2);

        return solveTabOpt(word1, word2);
    }
};