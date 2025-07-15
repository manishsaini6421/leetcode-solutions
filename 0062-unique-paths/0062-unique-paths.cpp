class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        if(i==0 || j==0)return 1;

        if(dp[i][j]!=-1)return dp[i][j];

        int left=solve(i,j-1,dp);
        int top=solve(i-1,j,dp);

        return dp[i][j]=left+top;
    }

    int solveTab(int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0; i<m; i++){
            dp[i][0]=1;
        }
        for(int j=0; j<n; j++){
            dp[0][j]=1;
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                 int left=dp[i][j-1];
                int top=dp[i-1][j];

                dp[i][j]=left+top;
            }
        }
        return dp[m-1][n-1];
    }

    int solveTabOpt(int m,int n){
       
        vector<int> prev(n,1);
        vector<int> curr(n,0);
        
        curr[0]=1;
      

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                 int left=curr[j-1];
                int top=prev[j];

                curr[j]=left+top;
            }
            prev=curr;
        }
        return prev[n-1];
    }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return solve(m-1,n-1,dp);

        // return solveTab(m,n);

        return solveTabOpt(m,n);
    }
};