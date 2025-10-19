class Solution {
public:
    // Recursion + DP (Top-Down)
    int solve(int n, int k, vector<int>& dp) {
        if (n == k)
            return 1;
        if (n < k)
            return 0;
        if (dp[k] != -1)
            return dp[k];
        int ans = solve(n, k + 1, dp) + solve(n, k + 2, dp);
        return dp[k] = ans;
    }

    int solveTab(int n){
        vector<int> dp(n+2);
        dp[n]=1;
        for(int k=n-1; k>=0; k--){
            dp[k]=dp[k+1]+dp[k+2];
        }
        return dp[0];
    }

    int solveOpt(int n){
        int curr=0,second=0,first=1;
        for(int k=n-1; k>=0; k--){
            curr=first+second;
            second=first;
            first=curr;
        }
        return first;
    }
    int climbStairs(int n) {
        // vector<int> dp(n, -1);
        // return solve(n, 0, dp);

        // return solveTab(n);

        return solveOpt(n);
    }
};