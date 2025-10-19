class Solution {
public:
    //Recursion + DP (Top-Down)
    int solve(int n, int k,vector<int> &dp){
        if(n==k)return 1;
        if(n<k)return 0;
        if(dp[k]!=-1)return dp[k];
        int ans=solve(n,k+1,dp)+solve(n,k+2,dp);
        return dp[k]=ans;
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return solve(n,0,dp);
    }
};