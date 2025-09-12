class Solution {
public:
    
    int solve(vector<int> &arr,int curr,int prev,vector<vector<int>> &dp){
       if(curr>=arr.size())return 0;

        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        int take=0;
        if(curr-1!=prev)take=arr[curr]+solve(arr,curr+1,curr,dp);

        int dontTake=solve(arr,curr+1,prev,dp);

        return dp[curr][prev+1]=max(take,dontTake);
    }
    int deleteAndEarn(vector<int>& nums) {
       
       int maxElement= *max_element(nums.begin(),nums.end());
       
       vector<int> arr(maxElement+1,0);

       int n=nums.size();
        
        for(int i=0; i<n; i++){
            arr[nums[i]]+=nums[i];
        }

        vector<vector<int>> dp(maxElement+1,vector<int>(maxElement+2,-1)); 
        int ans=solve(arr,0,-1,dp);
        return ans;
    }
};