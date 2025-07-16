class Solution {
public:
    int solve(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {

        if (target == 0)
            return 0;
        if (target < 0 || i >= nums.size())
            return INT_MIN;

        if (dp[target][i] != -2)
            return dp[target][i];

        int include = 1 + solve(nums, target - nums[i], i + 1, dp);
        int exclude = solve(nums, target, i + 1, dp);

        int ans = max(include, exclude);

        return dp[target][i] = (ans <= 0) ? -1 : ans;
    }

    int solveTab(vector<int>& nums, int total) {
        int n = nums.size();
        vector<vector<int>> dp(total + 1, vector<int>(n + 1, INT_MIN));

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int target = 1; target <= total; target++) {
            for (int i = n - 1; i >= 0; i--) {
                int include = INT_MIN;
                if (target - nums[i] >= 0 && dp[target - nums[i]][i + 1]!=INT_MIN)
                    include = 1 + dp[target - nums[i]][i + 1];
                int exclude = dp[target][i + 1];

                dp[target][i] = max(include, exclude);
            }
        }
        return (dp[total][0] <= 0) ? -1 : dp[total][0];
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        // int n = nums.size();
        // vector<vector<int>> dp(target + 1, vector<int>(n, -2));
        // return solve(nums, target, 0, dp);

        return solveTab(nums, target);
    }
};