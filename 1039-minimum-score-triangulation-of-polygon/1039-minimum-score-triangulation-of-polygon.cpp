class Solution {
public:
    int solve(vector<int>& v,int i,int j,vector<vector<int>> &dp){
        if(i+1==j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        
        int ans=INT_MAX;
        for(int k=i+1; k<j; k++){
            ans=min(ans,v[i]*v[j]*v[k]+solve(v,i,k,dp)+solve(v,k,j,dp));
        }
        return dp[i][j]=ans;
    }

    int solveTab(vector<int>& v){
        int n=v.size();

        vector<vector<int>> dp(n,vector<int> (n,INT_MAX));
        
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(i+1==j)dp[i][j]=0;
                else{

                    for(int k=i+1; k<j; k++){
                        dp[i][j]= min(dp[i][j],v[i]*v[j]*v[k] + dp[i][k]+dp[k][j]);
                    }
                }
               
            }
        }

        return dp[0][n-1];

       
    }

    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        // vector<vector<int>> dp(n,vector<int> (n,-1));
        // return solve(values,0,n-1,dp);

        return solveTab(values);
    }
};