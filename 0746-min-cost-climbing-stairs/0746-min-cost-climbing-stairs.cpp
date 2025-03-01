class Solution {
public:
    int solve(vector<int>& cost,int i,int n){
        if(i>=n)return 0;
        return cost[i]+min(solve(cost,i+1,n),solve(cost,i+2,n));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(cost,0,cost.size()),solve(cost,1,cost.size()));
    }
};