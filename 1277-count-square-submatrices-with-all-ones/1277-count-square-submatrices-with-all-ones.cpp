class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    int top = 0;
                    if (i > 0)
                        top = dp[i - 1][j];
                    int left = 0;
                    if (j > 0)
                        left = dp[i][j - 1];
                    int dig = 0;
                    if (i > 0 && j > 0)
                        dig = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min(dig, min(left, top));
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};