class Solution {
public:
    int solve(int index, int flag, vector<int>& prices, int fee) {
        if (index == prices.size())
            return 0;

        int buy = 0;
        int sell = 0;
        if (flag) {
            buy = solve(index + 1, 0, prices, fee) - prices[index] - fee;
        } else {
            sell = prices[index] + solve(index + 1, 1, prices, fee);
        }

        int skip = solve(index + 1, flag, prices, fee);

        return max(skip, max(buy, sell));
    }

    int solveMem(int index, int flag, vector<int>& prices, int fee,
                 vector<vector<int>>& dp) {
        if (index == prices.size())
            return 0;

        if (dp[index][flag] != -1)
            return dp[index][flag];
        int buy = 0;
        int sell = 0;
        if (flag) {
            buy = solveMem(index + 1, 0, prices, fee, dp) - prices[index] - fee;
        } else {
            sell = prices[index] + solveMem(index + 1, 1, prices, fee, dp);
        }

        int skip = solveMem(index + 1, flag, prices, fee, dp);

        return dp[index][flag] = max(skip, max(buy, sell));
    }

    int solveTab(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int flag = 0; flag <= 1; flag++) {
                int buy = 0;
                int sell = 0;
                if (flag) {
                    buy = dp[index + 1][0] -
                          prices[index] - fee;
                } else {
                    sell =
                        prices[index] + dp[index + 1][1];
                }

                int skip = dp[index + 1][flag];

                dp[index][flag] = max(skip, max(buy, sell));
            }
        }
        return dp[0][1];
    }

    int solveTabOpt(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> next(2,0);
        vector<int> curr(2,0);

        for (int index = n - 1; index >= 0; index--) {
            for (int flag = 0; flag <= 1; flag++) {
                int buy = 0;
                int sell = 0;
                if (flag) {
                    buy = next[0] -
                          prices[index] - fee;
                } else {
                    sell =
                        prices[index] + next[1];
                }

                int skip = next[flag];

                curr[flag] = max(skip, max(buy, sell));
            }
            next=curr;
        }
        return curr[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        // return solve(0,1,prices,fee);

        // int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // return solveMem(0, 1, prices, fee, dp);

        // return solveTab(prices,fee);

        return solveTabOpt(prices,fee);
    }
};