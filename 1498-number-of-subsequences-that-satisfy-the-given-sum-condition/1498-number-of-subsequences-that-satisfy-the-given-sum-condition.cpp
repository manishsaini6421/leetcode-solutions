#define MOD 1000000007
class Solution {
public:
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        vector<int> dp(n+1,0);

        dp[0]=1;
        for(int i=1; i<n; i++){
            dp[i]=(dp[i-1]*2)%MOD;
        }
        int i=0,j=n-1;
        int ans=0;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                ans= (ans + dp[j-i])%MOD;
                i++;
            }
            else j--;
        }
        return ans;
    }
};