class Solution {
public:
    int solveTabOptOpt(vector<int>& prices, int Limit) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(Limit + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int flag = 0; flag <= 1; flag++) {
                for (int limit = 1; limit <= Limit; limit++) {
                    int buy = 0;
                    int sell = 0;

                    if (flag) {
                        buy = curr[0][limit] - prices[index];
                    }

                    else {
                        sell = prices[index] + curr[1][limit - 1];
                    }
                    int skip = curr[flag][limit];

                    curr[flag][limit] = max(skip, max(buy, sell));
                }
            }
        }
        return curr[1][Limit];
    }
    int solve(int index, int OperationNo, int k, vector<int>& prices) {
        if (index == prices.size())
            return 0;
        if (OperationNo == 2 * k)
            return 0;

        int buy = 0;
        int sell = 0;
        if (OperationNo % 2 == 0) {
            buy = solve(index + 1, OperationNo + 1, k, prices) - prices[index];
        } else {
            sell = prices[index] + solve(index + 1, OperationNo + 1, k, prices);
        }

        int skip = solve(index + 1, OperationNo, k, prices);

        return max(skip, max(buy, sell));
    }

    int solveMem(int index, int OperationNo, int k, vector<int>& prices,
                 vector<vector<int>>& dp) {
        if (index == prices.size())
            return 0;
        if (OperationNo == 2 * k)
            return 0;

        if (dp[index][OperationNo] != -1)
            return dp[index][OperationNo];
        int buy = 0;
        int sell = 0;
        if (OperationNo % 2 == 0) {
            buy = solveMem(index + 1, OperationNo + 1, k, prices, dp) -
                  prices[index];
        } else {
            sell = prices[index] +
                   solveMem(index + 1, OperationNo + 1, k, prices, dp);
        }

        int skip = solveMem(index + 1, OperationNo, k, prices, dp);

        return dp[index][OperationNo] = max(skip, max(buy, sell));
    }
    int solveTab(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k+1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int OperationNo = 2 * k-1; OperationNo >= 0; OperationNo--) {
                int buy = 0;
                int sell = 0;
                if (OperationNo % 2 == 0) {
                    buy = dp[index + 1][OperationNo + 1] -
                          prices[index];
                } else {
                    sell = prices[index] +
                           dp[index + 1][OperationNo + 1];
                }

                int skip = dp[index + 1][OperationNo];

                dp[index][OperationNo] = max(skip, max(buy, sell));
            }
        }
        return dp[0][0];
    }

    int solveTabOpt(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2 * k+1, 0);
        vector<int> next(2 * k+1, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int OperationNo = 2 * k-1; OperationNo >= 0; OperationNo--) {
                int buy = 0;
                int sell = 0;
                if (OperationNo % 2 == 0) {
                    buy = next[OperationNo + 1] -
                          prices[index];
                } else {
                    sell = prices[index] +
                           next[OperationNo + 1];
                }

                int skip = next[OperationNo];

                curr[OperationNo] = max(skip, max(buy, sell));
            }
            next=curr;
        }
        return curr[0];
    }
    int maxProfit(int k, vector<int>& prices) {
        // return solveTabOptOpt(prices,k);

        // return solve(0,0,k,prices);

        // int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2 * k, -1));
        // return solveMem(0, 0, k, prices, dp);

        // return solveTab(k,prices);

        return solveTabOpt(k,prices);
    }
};