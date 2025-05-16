class Solution {
public:
    int solve(int index, int flag,vector<int>& prices,int fee){
        if(index==prices.size())return 0;

        int buy=0;
        int sell=0;
        if(flag){
            buy=solve(index+1,0,prices,fee)-prices[index]-fee;
        }
        else{
            sell=prices[index]+solve(index+1,1,prices,fee);
        }

        int skip=solve(index+1,flag,prices,fee);

        return max(skip,max(buy,sell));

    }

     int solveMem(int index, int flag,vector<int>& prices,int fee,vector<vector<int>> &dp){
        if(index==prices.size())return 0;

        if(dp[index][flag]!=-1)return dp[index][flag];
        int buy=0;
        int sell=0;
        if(flag){
            buy=solveMem(index+1,0,prices,fee,dp)-prices[index]-fee;
        }
        else{
            sell=prices[index]+solveMem(index+1,1,prices,fee,dp);
        }

        int skip=solveMem(index+1,flag,prices,fee,dp);

        return dp[index][flag]=max(skip,max(buy,sell));

    }
    int maxProfit(vector<int>& prices, int fee) {
        // return solve(0,1,prices,fee);

        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return solveMem(0,1,prices,fee,dp);

    }
};