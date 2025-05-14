class Solution {
public:
    int solve(int i,int j){
        if(i>=j)return 0;
        int ans=INT_MAX;
        for(int k=i; k<=j; k++){
            ans=min(ans,k+max(solve(i,k-1),solve(k+1,j)));
        }
       
        return ans;
    }
    int solveMem(int i,int j,vector<vector<int>> &dp){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i; k<=j; k++){
            ans=min(ans,k+max(solveMem(i,k-1,dp),solveMem(k+1,j,dp)));
        }
       
        return dp[i][j]=ans;
    }
    int getMoneyAmount(int n) {
       
        // return solve(1,n);

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveMem(1,n,dp);
    }
};