class Solution {
public:
    int solve(vector<int>& cost,int n,vector<int> &dp){
        if(n<=1)return cost[n];
        if(dp[n]!=-1)return dp[n];
        return dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    }
};