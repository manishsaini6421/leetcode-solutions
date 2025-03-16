class Solution {
public:
    int solve(vector<int>& obstacles, int pos, int currLane) {
        int n=obstacles.size() - 1;
        if (pos == n)
            return 0;
        if (currLane != obstacles[pos + 1]) {
            return solve(obstacles, pos + 1, currLane);
        }

        int ans = INT_MAX;
        for(int newLane=1; newLane<=3; newLane++){
            if(currLane!=newLane && obstacles[pos]!=newLane)
                ans=min(ans,1+solve(obstacles, pos, newLane));
        }
       
        return ans;
    }

    int solveMem(vector<int>& obstacles, int pos, int currLane,vector<vector<int>> &dp) {
        if (pos == obstacles.size() - 1)
            return 0;
        if(dp[pos][currLane]!=-1)return dp[pos][currLane];
        if (currLane != obstacles[pos + 1]) {
            return solveMem(obstacles, pos + 1, currLane,dp);
        }

        int ans = INT_MAX;
        for(int newLane=1; newLane<=3; newLane++){
            if(currLane!=newLane && obstacles[pos]!=newLane)
                ans=min(ans,1+solveMem(obstacles, pos, newLane,dp));
        }
       
        return dp[pos][currLane]=ans;
    }
    int minSideJumps(vector<int>& obstacles) { 
        int n=obstacles.size();
        vector<vector<int>> dp(n,vector<int>(4,-1)); 
        return solve(obstacles, 0, 2); 
        }
};