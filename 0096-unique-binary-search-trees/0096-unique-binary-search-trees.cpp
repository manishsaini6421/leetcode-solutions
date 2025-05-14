class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(n==0)return 1;
        if(n==1 || n==2)return n;
        if(n==3)return 5;
        if(dp[n]!=-1)return dp[n];
        int ans=0;
        for(int i=0; i<n; i++){
            ans+=(solve(i,dp)*solve(n-i-1,dp));
        }
        return dp[n]=ans;
    }
    int solveTab(int n){
        if(n==0)return 1;
        if(n==1 || n==2)return n;
        if(n==3)return 5;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int j=4; j<=n; j++){
            int ans=0;
            for(int i=0; i<n; i++){
                ans+=dp[i]*dp[j-i-1];
            }
            dp[j]=ans;
        }
        return dp[n];
    }
    int numTrees(int n) {
        // vector<int> dp(n+1,-1);
        // return solve(n,dp);

        return solveTab(n);
    }
};