class Solution {
public:
    int solveTabOptOpt(vector<int>& prices,int Limit) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(Limit + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int flag = 0; flag <= 1; flag++) {
                for (int limit = 1; limit <= Limit; limit++) {
                    int buy = 0;
                    int sell = 0;

                    if (flag) {
                        buy =curr[0][limit] -
                              prices[index];
                    }

                    else {
                        sell = prices[index] +
                               curr[1][limit - 1];
                    }
                    int skip = curr[flag][limit];

                    curr[flag][limit] = max(skip, max(buy, sell));
                }
            }
        }
        return curr[1][Limit];
    }
    int maxProfit(int k, vector<int>& prices) {
        return solveTabOptOpt(prices,k);
    }
};