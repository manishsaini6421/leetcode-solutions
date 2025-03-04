class Solution {
public:
    int solve(vector<int> &nums){
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        if(n>1)
            dp[1]=nums[1];
        for(int i=2; i<n; i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        int ans=(n>1)?max(dp[n-1],dp[n-2]):dp[n-1];
        return ans;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums);
    }
};