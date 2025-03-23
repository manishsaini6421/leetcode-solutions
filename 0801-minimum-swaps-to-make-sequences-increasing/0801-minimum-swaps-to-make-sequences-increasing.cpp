class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swaped) {
        if (index == nums1.size())
            return 0;

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        int ans = INT_MAX;

        if (swaped)
            swap(prev1, prev2);

        if (prev1 < nums1[index] && prev2 < nums2[index])
            ans = solve(nums1, nums2, index + 1, 0);

        if (prev1 < nums2[index] && prev2 < nums1[index])
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1));

        return ans;
    }

    int solveMem(vector<int>& nums1, vector<int>& nums2, int index, bool swaped,
                 vector<vector<int>>& dp) {
        if (index == nums1.size())
            return 0;

        if (dp[index][swaped] != -1) {
            return dp[index][swaped];
        }

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        int ans = INT_MAX;

        if (swaped)
            swap(prev1, prev2);

        if (prev1 < nums1[index] && prev2 < nums2[index])
            ans = solveMem(nums1, nums2, index + 1, 0, dp);

        if (prev1 < nums2[index] && prev2 < nums1[index])
            ans = min(ans, 1 + solveMem(nums1, nums2, index + 1, 1, dp));

        return dp[index][swaped] = ans;
    }

    int solveTab(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 1; index--) {
            for (int swaped = 1; swaped >= 0; swaped--) {
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                int ans = INT_MAX;

                if (swaped)
                    swap(prev1, prev2);

                if (prev1 < nums1[index] && prev2 < nums2[index])
                    ans = dp[index + 1][0];

                if (prev1 < nums2[index] && prev2 < nums1[index])
                    ans = min(ans, 1 + dp[index + 1][1]);

                dp[index][swaped] = ans;
            }
        }

        return dp[1][0];
    }

    int solveOpt(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        vector<int> next(2, 0);
        vector<int> curr(2, 0);

        for (int index = n - 1; index >= 1; index--) {
            for (int swaped = 1; swaped >= 0; swaped--) {
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                int ans = INT_MAX;

                if (swaped)
                    swap(prev1, prev2);

                if (prev1 < nums1[index] && prev2 < nums2[index])
                    ans = next[0];

                if (prev1 < nums2[index] && prev2 < nums1[index])
                    ans = min(ans, 1 + next[1]);

                curr[swaped] = ans;
            }
            next=curr;
        }

        return curr[0];
    }


    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        bool swaped = 0;

        // return solve(nums1, nums2, 1, swaped);

        // int n = nums1.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solveMem(nums1, nums2, 1, 0, dp);

        //return solveTab(nums1, nums2);

        return solveOpt(nums1,nums2);
    }
};