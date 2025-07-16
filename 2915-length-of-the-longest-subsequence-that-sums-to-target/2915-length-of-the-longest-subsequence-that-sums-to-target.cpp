class Solution {
public:
    int solve(vector<int>& nums, int target,int i,vector<vector<int>> &dp){
        
        if(target==0)return 0;
        if(target<0 || i>=nums.size())return INT_MIN;

        if(dp[target][i]!=-1)return dp[target][i];

        int include=1+solve(nums,target-nums[i],i+1,dp);
        int exclude=solve(nums,target,i+1,dp);
        
        int ans=max(include,exclude);

        if(ans<=0)return -1;
        return dp[target][i]=ans;

    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(target+1,vector<int> (n,-1));
        return solve(nums,target,0,dp);
    }
};