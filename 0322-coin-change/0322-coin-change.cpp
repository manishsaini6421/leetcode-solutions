class Solution {
public:
    int solve(vector<int>& coins, int amount, unordered_map<int, int>& dp) {
        if (amount == 0)
            return 0;

        if (amount < 0)
            return INT_MAX;

        if (dp.find(amount) != dp.end())
            return dp[amount];

        int ans = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int temp = solve(coins, amount - coins[i], dp);
            if (temp != INT_MAX)
                ans = min(ans, 1 + temp);
        }
        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {

        unordered_map<int, int> dp;
        int ans = solve(coins, amount, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};