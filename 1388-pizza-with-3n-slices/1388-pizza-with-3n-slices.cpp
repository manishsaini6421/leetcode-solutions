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

    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
      
        //return max(solve(slices,0,n-2,n/3),solve(slices,1,n-1,n/3));

         vector<vector<int>> dp(n,vector<int> (n/3+1,-1));
         int case1=solveMem(slices,0,n-2,n/3,dp);
         
         for(int i=0; i<n; i++){
            for(int j=0; j<=n/3; j++){
                dp[i][j]=-1;
            }
         }
         int case2=solveMem(slices,1,n-1,n/3,dp);
         return max(case1,case2);
    }
};