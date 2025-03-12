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

    // int solveTab(vector<int>& values){
    //     int n=values.size();

    //     vector<vector<int>> dp(n,vector<int> (n,INT_MAX));
        
    //     for(int i=0; i<n; i++){
    //         for(int j=0; j<n; j++){
    //             if(abs(j-i)<=1)dp[i][j]=0;
    //             if(abs(j-i)+1==3)dp[i][j]=values[i]*values[j]*((j-i>0)?values[i+1]:values[j+1]);
    //             else{

    //                 for(int k=i+1; k<j; k++){
    //                     dp[i][j]= min(dp[i][j],a*b*values[k] + dp[i][k]+dp[k][j]);
    //                 }
    //             }
               
    //         }
    //     }

    //     return dp[0][n-1];

       
    // }

    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(values,0,n-1,dp);
    }
};