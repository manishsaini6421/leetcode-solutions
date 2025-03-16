class Solution {
public:
    int solve(vector<int>& obstacles, int currLane, int pos) {
        int n=obstacles.size() - 1;
        if (pos == n)
            return 0;
        if (currLane != obstacles[pos + 1]) {
            return solve(obstacles, currLane, pos+1);
        }

        int ans = INT_MAX;
        for(int newLane=1; newLane<=3; newLane++){
            if(currLane!=newLane && obstacles[pos]!=newLane)
                ans=min(ans,1+solve(obstacles, newLane, pos));
        }
       
        return ans;
    }

    int solveMem(vector<int>& obstacles, int currLane, int pos,vector<vector<int>> &dp) {
        int n=obstacles.size() - 1;
        if (pos == n)
            return 0;
        if(dp[currLane][pos]!=-1)
            return dp[currLane][pos];

        if (currLane != obstacles[pos + 1]) {
            return solveMem(obstacles, currLane, pos+1,dp);
        }

        int ans = INT_MAX;
        for(int newLane=1; newLane<=3; newLane++){
            if(currLane!=newLane && obstacles[pos]!=newLane)
                ans=min(ans,1+solveMem(obstacles, newLane, pos,dp));
        }
       
        return dp[currLane][pos]=ans;
    }

    //   int solveTab(vector<int>& obstacles, int currLane, int pos) {
    //     int n=obstacles.size() - 1;
    //     if (pos == n)
    //         return 0;
    //     if(dp[currLane][pos]!=-1)
    //         return dp[currLane][pos];

    //     if (currLane != obstacles[pos + 1]) {
    //         return solveTab(obstacles, pos + 1, currLane,dp);
    //     }

    //     int ans = INT_MAX;
    //     for(int newLane=1; newLane<=3; newLane++){
    //         if(currLane!=newLane && obstacles[pos]!=newLane)
    //             ans=min(ans,1+solveTab(obstacles, pos, newLane,dp));
    //     }
       
    //     return dp[currLane][pos]=ans;
    // }

    int minSideJumps(vector<int>& obstacles) { 
        int n=obstacles.size();
       
        return solve(obstacles, 2, 0); 

         vector<vector<int>> dp(4,vector<int>(n,-1)); 
         //return solveMem(obstacles,2,0,dp);
     }
};