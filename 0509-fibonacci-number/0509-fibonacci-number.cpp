class Solution {
public:
    //Using recursion
    int solve(int n){
        if(n<=1)return n;
        return solve(n-1)+solve(n-2);
    }
    
    // Using DP-recursion(Top-Down)
    int solveMem(int n,vector<int> &dp){
        if(n<=1)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=solveMem(n-1,dp)+solveMem(n-2,dp);
    }

    //Using DP-Tabulation(Bottom-UP)
    int solveTab(int n){
        vector<int> dp(n+1);
        dp[0]=0;
        if(n>0) dp[1]=1;

        for(int i=2; i<=n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

    }

    //Using DP-Optimization(Bottom-UP)
    int solveOpt(int n){
        if(n<=1)return n;
        int prev=1,prev2=0;
        
        for(int i=2; i<=n; i++){
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
        
    }

    int fib(int n) {
        // return solve(n);

        // vector<int> dp(n+1,-1);
        // return solveMem(n,dp);


        // return solveTab(n);


        return solveOpt(n);
    }

};