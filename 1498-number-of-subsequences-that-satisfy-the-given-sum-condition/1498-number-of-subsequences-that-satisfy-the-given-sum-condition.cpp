#define MOD 1000000007
class Solution {
public:
    int pow(int a,int b){
        if(b==0)return 1;

        int temp=pow(a,b/2);
        if(b%2)return (temp*1l*temp*a)%MOD;
        return (temp*1l*temp)%MOD;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        vector<int> dp(n+1,0);

        dp[0]=1;
        dp[1]=2;
        for(int i=2; i<n; i++){
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