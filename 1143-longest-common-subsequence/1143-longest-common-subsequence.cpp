class Solution {
public:
    int solve(int i, int j, string& text1, string& text2) {
        if (i == text1.size() || j == text2.size())
            return 0;
        int length = 0;
        if (text1[i] == text2[j]) {
            length = 1 + solve(i + 1, j + 1, text1, text2);
        } else {
            length = max(solve(i + 1, j, text1, text2),
                         solve(i, j + 1, text1, text2));
        }
        return length;
    }

    int solveMem(int i, int j, string& text1, string& text2,
                 vector<vector<int>>& dp) {
        if (i == text1.size() || j == text2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int length = 0;
        if (text1[i] == text2[j]) {
            length = 1 + solveMem(i + 1, j + 1, text1, text2, dp);
        } else {
            length = max(solveMem(i + 1, j, text1, text2, dp),
                         solveMem(i, j + 1, text1, text2, dp));
        }
        return dp[i][j] = length;
    }

    int solveTab(string& text1, string& text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int length = 0;
                if (text1[i] == text2[j]) {
                    length = 1 + dp[i + 1][j + 1];
                } else {
                    length = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = length;
            }
        }
        return dp[0][0];
    }

    int solveTabOpt(string& text1, string& text2) {
        int m = text1.size();
        int n = text2.size();

        vector<int> next(n+1, 0);
        vector<int> curr(n+1, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int length = 0;
                if (text1[i] == text2[j]) {
                    length = 1 + next[j + 1];
                } else {
                    length = max(next[j], curr[j + 1]);
                }
                curr[j] = length;
            }
            next=curr;
        }
        return curr[0];
    }

    
    int longestCommonSubsequence(string text1, string text2) {

        // return solve(0,0,text1,text2);

        // int m = text1.size();
        // int n = text2.size();

        // vector<vector<int>> dp(m + 1, vector<int>(n, -1));

        // return solveMem(0, 0, text1, text2, dp);

        // return solveTab(text1, text2);

        return solveTabOpt(text1, text2);
    }
};