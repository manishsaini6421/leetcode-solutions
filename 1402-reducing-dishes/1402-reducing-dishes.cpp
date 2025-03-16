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
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        //return solve(satisfaction, 0, 0);

        int n=satisfaction.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return solveMem(satisfaction,0,0,dp);
    }
};