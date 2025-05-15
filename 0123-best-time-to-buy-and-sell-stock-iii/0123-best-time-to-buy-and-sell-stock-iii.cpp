class Solution {
public:
    int solve(int index, int flag, int limit, vector<int>& prices) {
        if (index == prices.size())
            return 0;
        if (limit == 0)
            return 0;
        int buy = 0;
        int sell = 0;
        if (flag) {
            buy = solve(index + 1, 0, limit, prices) - prices[index];
        }

        else {
            sell = prices[index] + solve(index + 1, 1, limit - 1, prices);
        }
        int skip = solve(index + 1, flag, limit, prices);

        return max(skip, max(buy, sell));
    }

    int solveMem(int index, int flag, int limit, vector<int>& prices,
                 vector<vector<vector<int>>>& dp) {
        if (index == prices.size())
            return 0;
        if (limit == 0)
            return 0;

        if (dp[index][flag][limit] != -1)
            return dp[index][flag][limit];
        int buy = 0;
        int sell = 0;

        if (flag) {
            buy = solveMem(index + 1, 0, limit, prices, dp) - prices[index];
        }

        else {
            sell =
                prices[index] + solveMem(index + 1, 1, limit - 1, prices, dp);
        }
        int skip = solveMem(index + 1, flag, limit, prices, dp);

        return dp[index][flag][limit] = max(skip, max(buy, sell));
    }
    int solveTab(vector<int>& prices) {
        int n = prices.size();
        int Limit = 2;
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(Limit + 1, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int flag = 0; flag <= 1; flag++) {
                for (int limit = 1; limit <= Limit; limit++) {
                    int buy = 0;
                    int sell = 0;

                    if (flag) {
                        buy = dp[index + 1][0][limit] -
                              prices[index];
                    }

                    else {
                        sell = prices[index] +
                               dp[index + 1][1][limit - 1];
                    }
                    int skip = dp[index + 1][flag][limit];

                    dp[index][flag][limit] = max(skip, max(buy, sell));
                }
            }
        }
        return dp[0][1][Limit];
    }

     int solveTabOpt(vector<int>& prices) {
        int n = prices.size();
        int Limit = 2;
        vector<vector<int>> curr(2, vector<int>(Limit + 1, 0));
        vector<vector<int>> next(2, vector<int>(Limit + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int flag = 0; flag <= 1; flag++) {
                for (int limit = 1; limit <= Limit; limit++) {
                    int buy = 0;
                    int sell = 0;

                    if (flag) {
                        buy =next[0][limit] -
                              prices[index];
                    }

                    else {
                        sell = prices[index] +
                               next[1][limit - 1];
                    }
                    int skip = next[flag][limit];

                    curr[flag][limit] = max(skip, max(buy, sell));
                }
            }
            next=curr;
        }
        return curr[1][Limit];
    }
    int maxProfit(vector<int>& prices) {
        // return solve(0,1,2,prices);

        // int n = prices.size();
        // int limit = 2;
        // vector<vector<vector<int>>> dp(
        //     n + 1, vector<vector<int>>(2, vector<int>(limit + 1, -1)));

        // return solveMem(0, 1, 2, prices, dp);

        // return solveTab(prices);

        return solveTabOpt(prices);
    }
};