class Solution {
public:
    int solve(vector<int>& slices,int index,int endIndex,int count){
        int n=slices.size();
        if(index>endIndex || count==0)return 0;
       
        int include=slices[index]+solve(slices,index+2,endIndex,count-1);
        
        int exclude=solve(slices,index+1,endIndex,count);
        
        return max(include,exclude);
    }

    int solveMem(vector<int>& slices,int index,int endIndex,int count, vector<vector<int>> &dp){
        int n=slices.size();
        if(index>endIndex || count==0)return 0;

        if(dp[index][count]!=-1)return dp[index][count];

        int include=slices[index]+solveMem(slices,index+2,endIndex,count-1,dp);
        
        int exclude=solveMem(slices,index+1,endIndex,count,dp);
        
        return dp[index][count]=max(include,exclude);
    }
    
    int solveTab(vector<int>& slices){
        int n=slices.size();
        vector<vector<int>> dp1(n+2,vector<int> (n/3+1,0));

        for(int index=n-2; index>=0; index--){
            for(int count=1; count<=n/3; count++){
                int include=slices[index]+dp1[index+2][count-1];
        
                int exclude=dp1[index+1][count];
        
                dp1[index][count]=max(include,exclude);
            }
        }

        vector<vector<int>> dp2(n+2,vector<int> (n/3+1,0));

        for(int index=n-1; index>=1; index--){
            for(int count=1; count<=n/3; count++){
                int include=slices[index]+dp2[index+2][count-1];
        
                int exclude=dp2[index+1][count];
        
                dp2[index][count]=max(include,exclude);
            }
        }

        return max(dp1[0][n/3],dp2[1][n/3]);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
      
        //return max(solve(slices,0,n-2,n/3),solve(slices,1,n-1,n/3));

        //  vector<vector<int>> dp1(n,vector<int> (n/3+1,-1));
        //  int case1=solveMem(slices,0,n-2,n/3,dp1);
         
        //  vector<vector<int>> dp2(n,vector<int> (n/3+1,-1));
        //  int case2=solveMem(slices,1,n-1,n/3,dp2);
        //  return max(case1,case2);

        return solveTab(slices);
    }
};