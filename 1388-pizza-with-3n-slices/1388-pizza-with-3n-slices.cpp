class Solution {
public:
    int solve(vector<int>& slices,int index,int count){
        int n=slices.size();
        if(index>=n || count>n/3)return 0;
       
        int include=slices[index]+solve(slices,index+2,count+1);
        
        int exclude=solve(slices,index+1,count);
        
        return max(include,exclude);
    }

    int solveMem(vector<int>& slices,int index,int count, vector<vector<int>> &dp){
        int n=slices.size();
        if(index>=n || count==0)return 0;

        if(dp[index][count]!=-1)return dp[index][count];

        int include=slices[index]+solveMem(slices,index+2,count-1,dp);
        
        int exclude=solveMem(slices,index+1,count,dp);
        
        return dp[index][count]=max(include,exclude);
    }

    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        vector<int> v1;
        vector<int> v2;
        for(int i=0; i<n; i++){
            if(i!=n-1){
                v1.push_back(slices[i]);
            }
            if(i!=0){
                v2.push_back(slices[i]);
            }
        }
      
        //return max(solve(v1,0,0),solve(v2,0,0));

         vector<vector<int>> dp1(n,vector<int> (n/3+1,-1));
         int case1=solveMem(v1,0,n/3,dp1);
         vector<vector<int>> dp2(n,vector<int> (n/3+1,-1));
         int case2=solveMem(v2,0,n/3,dp2);
         return max(case1,case2);
    }
};