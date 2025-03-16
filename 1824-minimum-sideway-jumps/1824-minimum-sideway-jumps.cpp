class Solution {
public:
    int solve(vector<int>& obstacles, int i, int lane,vector<vector<int>> &dp) {
        if (i == obstacles.size() - 1)
            return 0;
        if(dp[i][lane]!=-1)return dp[i][lane];
        if (lane != obstacles[i + 1]) {
            return solve(obstacles, i + 1, lane,dp);
        }

        int ans = INT_MAX;
        for(int k=1; k<=3; k++){
            if(lane!=k && obstacles[i]!=k)
                ans=min(ans,1+solve(obstacles, i, k,dp));
        }
       
        return dp[i][lane]=ans;
    }
    int minSideJumps(vector<int>& obstacles) { 
        int n=obstacles.size();
        vector<vector<int>> dp(n,vector<int>(4,-1)); 
        return solve(obstacles, 0, 2,dp); 
        }
};