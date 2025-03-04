class Solution {
public:
    bool solve(int n,int i,vector<int> &dp){
        if(n==0)return true;
        if(n<0 || i<0)return false;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=(solve(n,i-1,dp)  || solve(n-pow(3,i),i-1,dp));
    }
    bool checkPowersOfThree(int n) {
        int x=0;

        while(n>=pow(3,x)){
            x++;
        }
        vector<int> dp(n+1,-1);
        return solve(n,x-1,dp);
    }
};