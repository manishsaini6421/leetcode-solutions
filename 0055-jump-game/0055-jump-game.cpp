class Solution {
public:
    bool solveMem(vector<int>& nums, int index, vector<int>& dp) {
        if (index == nums.size() - 1)
            return true;
        if (index >= nums.size())
            return false;

        if (dp[index] != -1)
            return dp[index];
        bool ans = false;

        for (int i = 1; i <= nums[index]; i++) {
            bool temp = solveMem(nums, index + i, dp);
            if (temp)
                return dp[index] = true;
            ans |= temp;
        }
        return dp[index] = ans;
    }
    bool solveTab(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;
        for (int index = n - 2; index >= 0; index--) {
            bool ans = false;
            for (int i = 1; i <= nums[index]; i++) {

                if (index + i < n)
                    ans |= dp[index + i];
                if (ans)
                    break;
            }
            dp[index] = ans;
        }
        return dp[0];
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solveTab(nums);
    }
};