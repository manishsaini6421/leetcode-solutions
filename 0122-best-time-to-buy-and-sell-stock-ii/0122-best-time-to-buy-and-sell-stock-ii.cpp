class Solution {
public:
    int solve(int index, int flag, vector<int>& prices) {
        if (index >= prices.size())
            return 0;
        int buy = 0;
        if (flag) {
            buy = solve(index + 1, 0, prices)-prices[index];
        }
        int sell = 0;
        if (!flag) {
            sell = prices[index] +  solve(index + 1, 1, prices);
        }
        int skip = solve(index + 1, flag, prices);
        return max(skip, max(buy, sell));
    }

   

   int maxProfit(vector<int>& prices) {
        return solve(0, 1, prices);

        // int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solveMem(0, -1, prices, dp);

        //return solveTab(prices);
    }
};