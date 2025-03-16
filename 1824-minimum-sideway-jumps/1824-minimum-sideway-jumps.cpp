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
        int n=obstacles.size() - 1;
        if (pos == n)
            return 0;
        if(dp[currLane][pos]!=-1)
            return dp[currLane][pos];

        if (currLane != obstacles[pos + 1]) {
            return solveMem(obstacles, pos + 1, currLane,dp);
        }

        int ans = INT_MAX;
        for(int newLane=1; newLane<=3; newLane++){
            if(currLane!=newLane && obstacles[pos]!=newLane)
                ans=min(ans,1+solveMem(obstacles, pos, newLane,dp));
        }
       
        return dp[currLane][pos]=ans;
    }
    int minSideJumps(vector<int>& obstacles) { 
        int n=obstacles.size();
       
        //return solve(obstacles, 0, 2); 

         vector<vector<int>> dp(4,vector<int>(n,-1)); 
         return solveMem(obstacles,0,2,dp);
     }
};