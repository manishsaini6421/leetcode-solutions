class Solution {
public:
    int solve(vector<int>& satisfaction, int i, int time) {
        if (i == satisfaction.size())
            return 0;

        return max((time + 1) * satisfaction[i] +
                       solve(satisfaction, i + 1, time + 1),
                   solve(satisfaction, i + 1, time));
    }

    int solveMem(vector<int>& satisfaction, int i, int time,vector<vector<int>> &dp) {
        if (i == satisfaction.size())
            return 0;
        if(dp[i][time]!=-1)return dp[i][time];
        return dp[i][time]=max((time + 1) * satisfaction[i] +
                       solveMem(satisfaction, i + 1, time + 1,dp),
                   solveMem(satisfaction, i + 1, time,dp));
    }

    int solveTab(vector<int>& satisfaction){
        int n=satisfaction.size();

        vector<vector<int>> dp(n+1,vector<int> (n+1,0));

       
        for(int i=n-1; i>=0; i--){
            for(int time=n-1; time>=0; time--){
                dp[i][time]=max((time + 1) * satisfaction[i] + dp[i+1][time+1],dp[i+1][time]);
            }
        }
        return dp[0][0];
        
    }

    int solveOpt(vector<int>& satisfaction){
        int n=satisfaction.size();

        vector<int> next(n+1,0);
        vector<int> curr(n+1);

       

        for(int i=n-1; i>=0; i--){
            for(int time=n-1; time>=0; time--){
                curr[time]=max((time + 1) * satisfaction[i] + next[time+1],next[time]);
            }
            next=curr;
        }
        return curr[0];
        
    }

    int solveOpt_1D(vector<int>& satisfaction){
          int n=satisfaction.size();
           vector<int> curr(n+1,0);

           for(int i=n-1; i>=0; i--){
            for(int time=0; time<=n-1; time++){
                curr[time]=max((time + 1) * satisfaction[i] + curr[time+1],curr[time]);
            }
        }
        return curr[0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        //return solve(satisfaction, 0, 0);

        //int n=satisfaction.size();
        //vector<vector<int>> dp(n,vector<int>(n,-1));

       // return solveMem(satisfaction,0,0,dp);

       return solveTab(satisfaction);

       //return solveOpt(satisfaction);

       //return solveOpt_1D(satisfaction);
    }
};