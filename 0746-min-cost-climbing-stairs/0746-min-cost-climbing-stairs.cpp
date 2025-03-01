class Solution {
public:
    int solve(vector<int>& cost,int i,int n,vector<int> &dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=cost[i]+min(solve(cost,i+1,n,dp),solve(cost,i+2,n,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(solve(cost,0,cost.size(),dp),solve(cost,1,cost.size(),dp));
    }
};