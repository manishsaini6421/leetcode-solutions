class Solution {
public:
    // Recursion + DP (Top-Down)
    int solve(int n, int k, vector<int>& dp) {
        if (n == k)
            return 1;
        if (n < k)
            return 0;
        if (dp[k] != -1)
            return dp[k];
        int ans = solve(n, k + 1, dp) + solve(n, k + 2, dp);
        return dp[k] = ans;
    }

    int solveTab(int n){
        vector<int> dp(n+2);
        dp[n]=1;
        for(int k=n-1; k>=0; k--){
            dp[k]=dp[k+1]+dp[k+2];
        }
        return dp[0];
    }

    int solveOpt(int n){
        int curr=0,second=0,first=1;
        for(int k=n-1; k>=0; k--){
            curr=first+second;
            second=first;
            first=curr;
        }
        return first;
    }

    vector<vector<int>> matmul(vector<vector<int>> const &A, vector<vector<int>> const &B){
        int m=A.size();
        int n=A[0].size();
        int p=B[0].size();

        vector<vector<int>> C(m,vector<int> (p,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<p; j++){
                int sum=0;
                for(int k=0; k<n; k++){
                    sum+=A[i][k]*B[k][j];
                }
                C[i][j]=sum;
            }
        }
        return C;
    }
    vector<vector<int>> matpower(vector<vector<int>> const &A,int n){
        int m=A.size();

        vector<vector<int>> B(m,vector<int> (m,0));
        if(n==0){
            for(int i=0; i<m; i++){
                B[i][i]=1;
            }
        }
        if(n==1)return A;

        B=matpower(A,n/2);

        return (n%2)? matmul(matmul(B,B),A):matmul(B,B);
    }
    //Using matrix Exponention
    int solveMat(int n){
        vector<vector<int>> A={{0,1},{1,1}};
        vector<vector<int>> B={{1},{1}};
        vector<vector<int>> C{{0},{0}}; 
         C=matmul(matpower(A,n),B);
         return C[0][0];
    }

    int climbStairs(int n) {
        // vector<int> dp(n, -1);
        // return solve(n, 0, dp);

        // return solveTab(n);

        // return solveOpt(n);

        return solveMat(n);
    }
};