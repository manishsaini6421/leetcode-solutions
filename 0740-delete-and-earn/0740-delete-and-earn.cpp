class Solution {
public:
    int solve(vector<int>& arr, int index, int tookPrev,
              vector<vector<int>>& dp) {
        if (index >= arr.size())
            return 0;

        if (dp[index][tookPrev] != -1)
            return dp[index][tookPrev];
        int take = 0;
        if (!tookPrev)
            take = arr[index] + solve(arr, index + 1, 1, dp);

        int dontTake = solve(arr, index + 1, 0, dp);

        return dp[index][tookPrev] = max(take, dontTake);
    }

    int solveTab(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        for (int index = n - 1; index >= 0; index--) {
            for (int tookPrev = 1; tookPrev >= 0; tookPrev--) {
                int take = 0;
                if (!tookPrev)
                    take = arr[index] + solve(arr, index + 1, 1, dp);

                int dontTake = solve(arr, index + 1, 0, dp);

                dp[index][tookPrev] = max(take, dontTake);
            }
        }
        return dp[0][0];
    }
    int deleteAndEarn(vector<int>& nums) {

        int maxElement = *max_element(nums.begin(), nums.end());

        vector<int> arr(maxElement + 1, 0);

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            arr[nums[i]] += nums[i];
        }

        vector<vector<int>> dp(maxElement + 1, vector<int>(2, -1));
         
        // return solve(arr, 0, 0, dp);

         return solveTab(arr);
    }
};