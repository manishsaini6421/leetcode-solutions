class Solution {
public:
    bool solve(int n,int i,vector<int> &dp){
        int x=pow(3,i);
        if(n==x)return true;
        if(x>n || n<0)return false;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=(solve(n,i+1,dp)  || solve(n-x,i+1,dp));
    }
    bool checkPowersOfThree(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,0,dp);
    }
};