class Solution {
public:
    
    int solve(vector<int> &arr,int curr,int took,vector<vector<int>> &dp){
       if(curr>=arr.size())return 0;

        if(dp[curr][took]!=-1)return dp[curr][took];
        int take=0;
        if(!took)take=arr[curr]+solve(arr,curr+1,1,dp);

        int dontTake=solve(arr,curr+1,0,dp);

        return dp[curr][took]=max(take,dontTake);
    }
    int deleteAndEarn(vector<int>& nums) {
       
       int maxElement= *max_element(nums.begin(),nums.end());
       
       vector<int> arr(maxElement+1,0);

       int n=nums.size();
        
        for(int i=0; i<n; i++){
            arr[nums[i]]+=nums[i];
        }

        vector<vector<int>> dp(maxElement+1,vector<int>(2,-1)); 
        int ans=solve(arr,0,0,dp);
        return ans;
    }
};