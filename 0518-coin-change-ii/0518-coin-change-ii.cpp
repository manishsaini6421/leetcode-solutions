class Solution {
public:
    int solve(int amount, vector<int>& coins, int prev,
              vector<vector<int>>& dp) {
        if (amount == 0)
            return 1;
        if (amount < 0)
            return 0;

        if (dp[amount][prev] != -1)
            return dp[amount][prev];
        int ans = 0;
        int n = coins.size();
        for (int i = prev; i < n; i++) {
            ans += solve(amount - coins[i], coins, i, dp);
        }
        return dp[amount][prev] = ans;
    }

    int solveTab(int total, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(total + 1, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (int amount = 1; amount <= total; amount++) {
            for (int prev = n - 1; prev >= 0; prev--) {
                long long ans = 0;
                for (int i = prev; i < n; i++) {
                    if(amount-coins[i]>=0)
                        ans += dp[amount - coins[i]][i];
                       
                }
                dp[amount][prev] = ans;
            }
        }
        return dp[total][0];
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
        //return solve(amount, coins, 0, dp);
        return solveTab(amount,coins);
    }
};