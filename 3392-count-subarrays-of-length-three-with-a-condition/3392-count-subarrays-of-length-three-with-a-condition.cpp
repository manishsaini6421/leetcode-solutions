class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=2; i<n; i++){
            if(nums[i-1]%2==0 && nums[i]+nums[i-2]==nums[i-1]/2)ans++;
        }
        return ans;
    }
};