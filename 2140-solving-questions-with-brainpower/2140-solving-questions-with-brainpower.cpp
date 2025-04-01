class Solution {
public:
    long long solve(vector<vector<int>>& questions,int index){
        if(index>=questions.size())return 0;

        int include=questions[index][0]+solve(questions,index+questions[index][1]+1);
        int exclude=solve(questions,index+1);
        return max(include,exclude);
    }

     long long solveMem(vector<vector<int>>& questions,int index,vector<long long> &dp){
        if(index>=questions.size())return 0;

        if(dp[index]!=-1)return dp[index];

        long long include=questions[index][0]+solveMem(questions,index+questions[index][1]+1,dp);
        long long exclude=solveMem(questions,index+1,dp);
        return dp[index]=max(include,exclude);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        //return solve(questions,0);

        int n=questions.size();
        vector<long long> dp(n,-1);
        return solveMem(questions,0,dp);
    }
};