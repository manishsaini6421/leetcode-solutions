class Solution {
public:
    
    int solveTab(vector<int>& nums, int n, int target) {
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));

        for(int i=0; i<n; i++){
            dp[i][0]=true;
        }
        for(int j=0; j<=target; j++){
            dp[0][j]=(nums[0]==j)?true:false;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<=target; j++){
                bool take=false;
                if(j-nums[i]>=0)take=dp[i-1][j-nums[i]];
                bool dontTake=dp[i-1][j];
                dp[i][j]=(take || dontTake);
            }
        }
       
        return dp[n-1][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

       // vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
        if (sum % 2)
            return false;
        return solveTab(nums, n , sum / 2);
    }
};