class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
        vector<int> dp(n+1);
        
        for(int i=2; i<=n; i++){
            int oneStep = dp[i-1]+cost[i-1];
            int twoStep =dp[i-2]+cost[i-2];
            dp[i]=min(oneStep,twoStep);
        }
        return dp[n];
    }
};