class Solution {
public:
    bool solve(vector<int>& nums,int index,int sum,int total){
        if(sum==total)return true;
        if(index>=nums.size())return false;

        bool include=solve(nums,index+1,sum+nums[index],total);
        bool exclude=solve(nums,index+1,sum,total);

        return include || exclude;
    }
   
   bool solveMem(vector<int>& nums,int index,int sum,int total,vector<vector<int>> &dp){
        if(sum==total)return true;
        if(index>=nums.size())return false;

        if(dp[index][sum]!=-1)return dp[index][sum];

        bool include=solveMem(nums,index+1,sum+nums[index],total,dp);
        bool exclude=solveMem(nums,index+1,sum,total,dp);

        return dp[index][sum]=include || exclude;
    }

    bool solveTab(vector<int>& nums){
        int n=nums.size();
        int total=0;
        for(int i=0; i<n; i++){
            total+=nums[i];
        }
        if(total%2)return false;
        total/=2;

        vector<vector<int>> dp(n+1,vector<int>(total+1,0));
        
        for(int i=0; i<=n; i++){
            dp[i][total]=1;
        } 
        
        for(int index=n-1; index>=0; index--){
            for(int sum=0; sum<total; sum++){
                bool include=false;
                if(sum+nums[index]<=total)
                include=dp[index+1][sum+nums[index]];
                bool exclude=dp[index+1][sum];

                dp[index][sum]=include || exclude;
            }
        }
        return dp[0][0];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2)return false;
        
        //return solve(nums,0,0,sum/2);

        // vector<vector<int>> dp(n,vector<int>(sum,-1));
        // return solveMem(nums,0,0,sum/2,dp);

        return solveTab(nums);
    }
};