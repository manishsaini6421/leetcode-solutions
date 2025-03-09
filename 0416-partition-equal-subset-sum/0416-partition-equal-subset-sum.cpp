class Solution {
public:
    int solve(vector<int>& nums, int index, int target,
              vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (target < 0)
            return false;
        if (index < 0)
            return false;
        if (dp[index][target] != -1)
            return dp[index][target];
        return dp[index][target] =
                   (solve(nums, index - 1, target - nums[index], dp) ||
                    solve(nums, index - 1, target, dp));
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
        if (sum % 2)
            return false;
        return solve(nums, n-1 , sum / 2,dp);
    }
};