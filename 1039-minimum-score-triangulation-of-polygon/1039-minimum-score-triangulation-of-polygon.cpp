class Solution {
public:
    int solve(vector<int>& values,int i,int j,vector<vector<int>> &dp){
        if(i+1==j)return 0;
        if(j-i+1==3)return values[i]*values[i+1]*values[j];

        if(dp[i][j]!=-1)return dp[i][j];
        int a=values[i];
        int b=values[j];

        int ans=INT_MAX;

        for(int k=i+1; k<j; k++){
            ans=min(ans,a*b*values[k]+solve(values,i,k,dp)+solve(values,k,j,dp));
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(values,0,n-1,dp);
    }
};